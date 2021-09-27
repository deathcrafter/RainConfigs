function dostring(string)
    f=loadstring(string)
    setfenv(f, getfenv())
    return f
end

configArrays={}

showList={}

some={{{{'Key'}}}}

function Add(tableX)
    for k, v in pairs(tableX) do
        if type(v)~='table' then 
            print(v)
        else
            Add(v)
        end
    end
end

function Initialize()
    Add(some)
    rainmeter=ReadIni(SKIN:GetVariable('SETTINGSPATH')..'Rainmeter.ini')
    local file=io.open(SKIN:GetVariable('@')..'Configs.inc', 'r')
    local configs={}
    for line in file:lines() do
        if line ~= '' then
            table.insert(configs, line)
        end
    end
    file:close()

    for i=1, #configs do
        local temp={}
        for parts in configs[i]:gmatch('[^\\]+') do
            table.insert(temp, parts)
        end
    end
end

function MakeNestedConfig()
    local m=1
    for k,v in ipairs(configs) do
        local temp={}
        for parts in v:gmatch('[^\\]+') do
            table.insert(temp, parts)
        end
        rootConfig=temp[1]
        if not configArrays[rootConfig] then
            configArrays[rootConfig]={}
            if not rainmeter['INI'][rootConfig] then configArrays[rootConfig].Active=0 else configArrays[rootConfig].Active=rainmeter['INI'][rootConfig]['Active'] end
        end
        configArrays[rootConfig].Open=0
        local tempString=''
        local tempConfig=rootConfig
        for i=2, #temp do
            if temp[i]:match('%.ini$') then
                if dostring("if not configArrays[rootConfig]"..tempString.."['INI'] then return true else return false end")() then
                    dostring("configArrays[rootConfig]"..tempString.."['INI']={}")()
                end
                dostring("table.insert(configArrays[rootConfig]"..tempString.."['INI'], '"..temp[i].."')")()
            else
                prevTempString=tempString
                prevTempConfig=tempConfig
                tempString=tempString.."['"..temp[i].."']"
                tempConfig=tempConfig.. "\\" ..temp[i]
                local active=0
                if not not rainmeter['INI'][tempConfig] then
                    active=rainmeter['INI'][tempConfig]['Active']
                    dostring("configArrays[rootConfig]"..prevTempString..".ActiveCount=configArrays[rootConfig]"..prevTempString..".ActiveCount and configArrays[rootConfig]"..prevTempString..".ActiveCount+1 or 0")
                end
                if dostring("if not configArrays[rootConfig]"..tempString.." then return true else return false end")() then
                    dostring("configArrays[rootConfig]"..tempString.."={}; configArrays[rootConfig]"..tempString..".Open=0")()
                    dostring("")()
                end
            end
        end
    end
end

function contains(table1, content)
    for k, v in pairs(table1) do
        if type(content)=='table' and type(v)=='table' then
            if table.equals(v, content) then return true end
        else
            if v==content then return true end
        end
    end
    return false
end

function table.equals(table1, table2)
    if #table1~=#table2 then return false end
    for k, v in pairs(table1) do
        if not table2[k] then return false end
        if table2[k]~=v then return false end
    end
    return true
end

function MakeShowList(arg)
    if arg==nil then return {''} end
    argkeys=sortByKey(arg)
    for _, v in ipairs(argkeys) do
        if v~='INI' then
            if arg[v].Open==1 then
                MakeShowList(arg[v])
            end
        else
            for k,V in arg[v] do
                table.insert(showList, V)
            end
        end
    end
end

function sortByKey(table)
    local tempTable={}
    for k, v in pairs(table) do table.insert(tempTable, k) end
    table.sort(tempTable, function(a, b) return a:lower() < b:lower() end)
    return tempTable
end

function ReadIni(inputfile)
	local file = assert(io.open(inputfile, 'r'), 'Unable to open ' .. inputfile)
	local tbl, section = {}
    local sectionReadOrder, keyReadOrder = {}, {}
	local num = 0
	for line in file:lines() do
        --print(line)
		num = num + 1
		if not line:match('^%s-;') then
			local key, command = line:match('^([^=]+)=(.+)')
			if line:match('^%s-%[.+') then
				section = line:match('^%s-%[([^%]]+)')
				if not tbl[section] then
                    tbl[section]={}
                    table.insert(sectionReadOrder, section)
                    if not keyReadOrder[section] then keyReadOrder[section]={} end
                end
			elseif key and command and section then
				tbl[section][key:match('^%s*(%S*)%s*$')] = command:match('^%s*(.-)%s*$')
                table.insert(keyReadOrder[section], key)
                --print(keyReadOrder[section][table.maxn(keyReadOrder[section])])
			elseif #line > 0 and section and not key or command then
				print(num .. ': Invalid property or value.')
			end
		end
	end
    file:close()

    if not section then print('No sections found in ' .. inputfile) return end

    local finalTable={}
    finalTable.INI=tbl
    finalTable.SectionOrder=sectionReadOrder
    finalTable.KeyOrder=keyReadOrder
    return finalTable
end