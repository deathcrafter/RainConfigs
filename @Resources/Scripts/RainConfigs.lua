activecount = 0
function Initialize()
    dofile(SKIN:GetVariable('@')..[[Scripts\Configs.lua]])
    dofile(SKIN:GetVariable('@')..[[Scripts\Meters.lua]])
    InitiateConfigs()
    SetMeters()
    activecount = SKIN:ReplaceVariables("[&ConfigActive:LoadedCount()]")
end

function Update()
    local act = SKIN:ReplaceVariables("[&ConfigActive:LoadedCount()]")
    if act ~= activecount then
        ChangeActiveState()
        SetMeters()
        activecount = act
    end
end

function SetMeters()
    meterArray = {}
    root = ''
    prevRoot = ''
    local scale = tonumber(SKIN:GetVariable('Scale'))
    local prevhori = tonumber(SKIN:GetVariable('horizontalScrollHori'))
    local olddiff = GetWidth() - 250*scale
    local index = tonumber(SKIN:GetVariable('Index'))
    oldpos = math.floor(prevhori*olddiff+0.5)
    SKIN:Bang('!SetVariable', 'horizontalScrollHori', 0)
    widestmet = 0
    setMeters()
    local newdiff=GetWidth() - 250*scale
    local horizontalscrollhori = 0
    if newdiff > olddiff then
        horizontalscrollhori = oldpos/newdiff
    elseif newdiff < olddiff then
        if (oldpos > newdiff) and (newdiff > 0) then
            horizontalscrollhori = 1
        elseif (oldpos <= newdiff) and (newdiff > 0) then
            horizontalscrollhori = oldpos/newdiff
        end
    else
        horizontalscrollhori = prevhori
    end
    if (#meterArray) <= index + 20 then SKIN:Bang('!SetVariable', 'Index', #meterArray - 20) end
    SKIN:Bang('!SetVariable', 'horizontalScrollHori', horizontalscrollhori)
    SKIN:Bang('!UpdateMeasureGroup', 'Scroll')
    SKIN:Bang('!UpdateMeterGroup', 'Scroll')
    SKIN:Bang('!UpdateMeter', '*')
    SKIN:Bang('!Redraw')
end

function GetProp(index, key)
    index=index=='dummy' and index or SKIN:ParseFormula(index)
    if meterArray[index] then
        -- if (index == 'dummy') then print('dum') end
        return meterArray[index][key]
    else
        local met=meter:new()
        return met[key]
    end
end

function GetN()
    return #meterArray
end

function GetWidth()
    return widestmet < 250*tonumber(SKIN:GetVariable('Scale')) and 250*tonumber(SKIN:GetVariable('Scale')) or widestmet
end

function dostring(string)
    f=loadstring(string)
    setfenv(f, getfenv())
    return f
end

function ReadIni(measureName)
	local rainsettings = string.split(SKIN:GetMeasure(measureName):GetStringValue(), '||')
	local tbl, section = {}
    local sectionReadOrder, keyReadOrder = {}, {}
	local num = 0
	for _, line in ipairs(rainsettings) do
        --print(line)
		num = num + 1
		if not line:match('^%s-;') then
			local key, command = line:match('^([^=]+)=(.+)')
			if line:match('^%s-%[.+') then
				section = line:match('^%s-%[([^%]]+)')
                section=section or 'luafillerxxx87654312890'
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

    if not section then print('No sections found in ' .. inputfile) return end

    local finalTable={}
    finalTable.INI=tbl
    finalTable.SectionOrder=sectionReadOrder
    finalTable.KeyOrder=keyReadOrder
    return finalTable
end

function string.split(inString, inPattern)

	local outTable = {}
	local findPattern = '(.-)' .. inPattern
	local lastEnd = 1

	local currentStart, currentEnd, foundString = inString:find(findPattern, 1)

	while currentStart do
		if currentStart ~= 1 or foundString ~= '' then
			table.insert(outTable, foundString)
		end
		lastEnd = currentEnd + 1
		currentStart, currentEnd, foundString = inString:find(findPattern, lastEnd)
	end

	if lastEnd <= #inString then
		foundString = inString:sub(lastEnd)
		table.insert(outTable, foundString)
	end

	return outTable

end

function table.contains(table, value, type)
    if type == "key" then
        for k, _ in pairs(table) do
            if value == k then return true end
        end
    elseif type == "value" then
        for _, v in pairs(table) do
            if value == v then return true end
        end
    end
end