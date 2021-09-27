function Update {
    $RmAPI.Log('Started!')
    try{Get-Configs}catch{$RmAPI.Log($_)}
    $RmAPI.Bang('[!PauseMeasure RainRM]')
}

$scale=$RmAPI.Variable('Scale')
$skinsPath=$RmAPI.VariableStr('SKINSPATH')
$settingsPath=$RmAPI.VariableStr('SETTINGSPATH')

class config {
    $name=''
    $root=''
    $level=0
    $ini=$false
    $active=0
    $configsActive=$false
    $open=0
}

$configs=[ordered]@{}
$configArray=[ordered]@{}

class meter {
    $x=10*$scale
    $text=""
    $image='folder0'
    $greyscale=0
    $hidden=1
    $lmb=''
}

$meterArray=[ordered]@{}

New-Variable rainmeter
function Get-Configs {
    # $RmAPI.Log('Clearing configs!')
    $configs.Clear()
    # $RmAPI.Log('Cleared configs!')
    $k=1
    $tempArray=Get-ChildItem -Path $skinsPath -File -Recurse -Filter '*.ini' | Where-Object FullName -notmatch '@Backup|@Vault|@Resources' | ForEach-Object {$_.FullName -replace $($skinsPath -replace '\\', '\\'), ''}
    $tempArray | ForEach-Object {
        # $RmAPI.Log($_)
        $configs.Add($k, $_)
        $k++
    }
    $RmAPI.Log('Getting rainmeter settings!')
    Get-RainSettings
}
function Get-RainSettings() {
    $rainmeter=ReadIni($settingsPath+'Rainmeter.ini')
    Resolve-Configs
}
function Resolve-Configs {
    $configArray.Clear()
    # $RmAPI.Log($configs.Count)
    for ($i=1; $i -lt $configs.Count; $i++) {
        # $RmAPI.Log($configs[$i])
        $temp=$configs[$i] -split '\\'
        $str=''
        for($j=0; $j -lt $temp.Count; $j++) {
            $curr=if ($str -eq '') {$temp[$j]} else {$str+$temp[$j]}
            $present=$false
            $configArray.GetEnumerator() | ForEach-Object {
                if (($_.Value.root -eq $str) -and ($_.Value.name -eq $temp[$j])) {
                    $present=$true
                }
            }
            if (-not $present) {
                $conf = [config]::new()
                $conf.name=$temp[$j]
                $conf.root=$str
                $conf.level=$j
                $conf.ini=$temp[$j] -match '\.ini$'
                $conf.active=if ($null -eq $rainmeter[$curr]) {0} else {$rainmeter[$curr].Active}
                $configArray.Add($configArray.Count+1, $conf)
            }
            $str=$curr
        }
    }
    printConfigs
    # $RmAPI.Log($configArray.Count)
}
function Set-MeterArray {

}
function Set-Configs($root) {
    $confs=@()
    $inis=@()
    $configArray.GetEnumerator() | ForEach-Object {
        if ($_.Value.root -eq $root) {
            if ($_.Value.ini) {$inis+=$_.Value} else {$confs+=$_.Value}
        }
    }
    return @{
        confs=$confs
        inis=$inis
    }
}
function printConfigs {
    $configArray.GetEnumerator() | ForEach-Object {
        if ($_.Value.root -eq '') {
            $RmAPI.Log($_.Value.name)
        }
    }
}

function ReadIni($filePath)
{
    $ini = @{}
    $content=Get-Content -Path $filePath
    switch -regex ($content)
    {
        “^\[(.+)\]” # Section
        {
            $section = $matches[1]
            $ini[$section] = @{}
            $CommentCount = 0
        }
        “^(;.*)$” # Comment
        {
            $value = $matches[1]
            $CommentCount = $CommentCount + 1
            $name = “Comment” + $CommentCount
            $ini[$section][$name] = $value
        }
        “(.+?)\s*=(.*)” # Key
        {
            $name,$value = $matches[1..2]
            $ini[$section][$name] = $value
        }
    }
    return $ini
}