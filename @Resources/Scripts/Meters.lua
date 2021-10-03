meter = {}

metameters = {
    __index = {
        x = (10)*tonumber(SKIN:GetVariable('Scale')),
        text = "'",
        image = 'folder0',
        tint='',
        activecolor='0,0,0,0',
        containsactivecolor='0,0,0,0',
        hidden=1,
        lmb='',
        w=0
    }
}

setmetatable(meter, metameters)

function meter:new()
    local met={}
    setmetatable(met, metameters)
    return met
end

meterArray={}

root=''
prevRoot=''

widestmet = 0

function setMeters()
    local conf=getConfigs(root)
    for k, v in ipairs(conf.confs) do
        local met=meter:new()
            met.x=(10+10*v.level)*tonumber(SKIN:GetVariable('Scale'))
            met.text=v.name
            if v.open==1 then met.image='folder1' end
            if (v.active > 0) and (v.configsActive) then
                met.activecolor = '30,212,96'
                met.containsactivecolor = '0,122,204'
            elseif (v.active > 0) and (not v.configsActive) then
                met.activecolor = '30,212,96'
            elseif (v.active < 0) and (v.configsActive) then
                met.activecolor = '147,147,147'
                met.containsactivecolor = '0,122,204'
            end
            if v.configsActive then met.tint = '0,255,0' end
            met.hidden=0
            met.lmb='[!CommandMeasure RainConfigs "configArray['..v.index..']()"]'
            meterArray['dummy']=met 
            SKIN:Bang('!UpdateMeterGroup', 'Dummy')
            met.W = SKIN:GetMeter('Dummy'):GetX() + SKIN:GetMeter('Dummy'):GetW()
            widestmet = (met.W > widestmet and met.W or widestmet)
        table.insert(meterArray, met)
        if v.open==1 then
            root=root .. (root~='' and '\\' or '') .. v.name
            setMeters()
            root=v.root
        end
    end
    for k, v in ipairs(conf.inis) do
        local met=meter:new()
            met.x=(10+10*v.level)*tonumber(SKIN:GetVariable('Scale'))
            met.text=v.name
            met.image='ini'
            if v.iniActive then met.activecolor='30,212,96' end
            met.hidden=0
            met.lmb='[!CommandMeasure RainConfigs "configArray['..v.index..']()"]'
            meterArray['dummy']=met 
            SKIN:Bang('!UpdateMeterGroup', 'Dummy')
            met.W = SKIN:GetMeter('Dummy'):GetX() + SKIN:GetMeter('Dummy'):GetW()
            widestmet = met.W > widestmet and met.W or widestmet
        table.insert(meterArray, met)
    end
end

function getConfigs(rootN)
    local confs={}
    local inis={}
    for k, v in ipairs(configArray) do
        if v.root==rootN then
            v.index=k
            if v.ini then table.insert(inis, v) else table.insert(confs, v) end
        end
    end
    local o={confs=confs, inis=inis}
    return o
end