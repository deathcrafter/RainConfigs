metadata = {}

metatable = {
    __index = {
        name = "...",
        root = "",
        author = "",
        version = "",
        license = "",
        infoheader = "",
        information = "",
        link = "",
        rootpath = "",
        currentpath = "",
        preview = "{resources}dummypreview.png"
    }
}


setmetatable(metadata, metatable)

function metadata:new()
    local meta = {}
    setmetatable(meta, metatable)
    return meta
end

config={}

metaconfig={ 
    __index = {
        index = 0,
        name = '',
        ini = false,
        root = '',
        active = 0,
        iniActive = false,
        activeIni = '',
        metadata = metadata:new(),
        settings = {}
    },
    __call = function (table)
        if table.ini then
            currentmetadata = table.metadata
            UpdatePanel()
        end
    end
}

setmetatable(config,metaconfig)

function config:new()
    local conf = {}
    setmetatable(conf, metaconfig)
    return conf
end

-------------------------------------------------------------------------

configArray = {} -- type: config
configList = {} -- type: string

-- to be called once, upon refresh
function InitiateConfigs() -- type: null

    -- empty the config array and config list
    configArray = {}
    configList = {}

    -- get the list of all activate-able ini files
    local configs=string.split(SKIN:GetMeasure('ListConfigs'):GetStringValue(), "|")

    local count = 1
    for k, v in ipairs(configs) do
        local temp=string.split(v, [[\]])
        

        -- stores the prev config obtained by joining temp elements
        local str = ''

        -- now join the file paths from the beginning one by one and check if the config already exists in 'configsArray'
        -- if not, create a new entry
        for i = 1, #temp do

            -- current string/config obtained by joining temp elements
            local curr = str == '' and temp[i] or str..[[\]]..temp[i]

            local contains = table.contains(configList, curr, "key")
            
            if not contains then
                local conf = config:new()

                conf.name=temp[i]
                if str~='' then conf.root=str end
                if temp[i]:match('%.ini$') then conf.ini=true end
                conf.level = i-1
                
                if not conf.ini then conf.active = tonumber(SKIN:ReplaceVariables("[&ConfigActive:IsActive("..curr..")]")) end

                if conf.active > 0 then
                    if (conf.root ~= '') then
                        setActive(conf.root) 
                    end
                    conf.activeIni=SKIN:ReplaceVariables("[&ConfigActive:ConfigVariantName("..curr..")]")
                end

                if conf.ini then
                    if conf.name:lower() == configArray[configList[conf.root]].activeIni:lower() then
                        conf.iniActive = true
                    end
                    conf.metadata = ReadMetadata(SKIN:GetVariable('SKINSPATH')..conf.root..[[\]]..conf.name)
                    conf.metadata.name = conf.name
                    conf.metadata.root = conf.root
                    conf.metadata.rootpath = SKIN:GetVariable('SKINSPATH') .. conf.root:gsub('^(.-)\\', '%1') .. '\\'
                    conf.metadata.currentpath = SKIN:GetVariable('SKINSPATH') .. conf.root .. '\\'
                end

                conf.open=0
                table.insert(configArray, conf)
                if not conf.ini then configList[curr] = table.maxn(configArray) end
            end
            str=curr
        end
    end
end

function setActive(str) -- type: null
    local TEMP = string.split(str, [[\]])
    local STR = ''
    for i=1, #TEMP do
        local CURR = STR .. (STR=='' and '' or [[\]])..TEMP[i]
        configArray[configList[CURR]].configsActive=true
        STR = CURR
    end
end

-- changes the active state of conifgs in configsArray
-- called when config count changes
function ChangeActiveState() -- type: null
    for k, v in ipairs(configArray) do
        if not v.ini then
            configArray[k].active = tonumber(SKIN:ReplaceVariables("[&ConfigActive:IsActive(".. v.root .. (v.root == '' and '' or [[\]]) .. v.name ..")]"))
            configArray[k].configsActive = false
            if configArray[k].active > 0 then
                setActive(configArray[k].root)
                configArray[k].activeIni = SKIN:ReplaceVariables("[&ConfigActive:ConfigVariantName(".. v.root .. (v.root == '' and '' or [[\]]) .. v.name ..")]")
            else
                configArray[k].activeIni = ''
            end
        end
        if v.ini then
            if v.name:lower() == configArray[configList[v.root]].activeIni:lower() then
                configArray[k].iniActive = true
            else
                configArray[k].iniActive = false
            end
        end
    end
end

-- current metadata
currentmetadata = metadata:new()

-- read all the ini files and get the metadata 
function ReadMetadata(ini)
    SKIN:Bang('!SetOption', 'ReadINI', 'FilePath', ini)
    SKIN:Bang('!UpdateMeasure', 'ReadINI')
    --print(ini .. '::' .. SKIN:GetMeasure('ReadINI'):GetStringValue())
    local iniTable = ReadIni('ReadINI')
    if not table.contains(iniTable.SectionOrder, 'metadata') then return metadata:new() end
    local o = metadata:new()
    local keys = {'Author', 'Version', 'License', 'Information', 'Link', 'Preview'}
    for index, key in pairs(keys) do
        if table.contains(iniTable.KeyOrder['metadata'], key:lower()) then o[key:lower()] = (key == 'Information' and ' ' or '') .. iniTable.INI['metadata'][key:lower()] end
    end
    return o
end

function ReadIni(measureName)
	local inifile = string.split(SKIN:GetMeasure(measureName):GetStringValue(), ';|::|::|;')
	local tbl, section = {}
    local sectionReadOrder, keyReadOrder = {}, {}
	local num = 0
	for _, line in ipairs(inifile) do
        --print(line)
		num = num + 1
		if not line:match('^%s-;') then
			local key, command = line:match('^([^=]+)=(.+)')
			if line:match('^%s-%[.+') then
				section = line:match('^%s-%[([^%]]+)')
                section=section:lower() or 'luafillerxxx87654312890'
				if not tbl[section] then
                    tbl[section]={}
                    table.insert(sectionReadOrder, section:lower())
                    if not keyReadOrder[section] then keyReadOrder[section]={} end
                end
			elseif key and command and section then
				tbl[section][key:match('^%s*(%S*)%s*$'):lower()] = command:match('^%s*(.-)%s*$')
                table.insert(keyReadOrder[section], key:lower())
                --print(keyReadOrder[section][table.maxn(keyReadOrder[section])])
			elseif #line > 0 and section and not key or command then
				--print(num .. ': Invalid property or value.')
			end
		end
	end

    local finalTable={}
    finalTable.INI=tbl
    finalTable.SectionOrder=sectionReadOrder
    finalTable.KeyOrder=keyReadOrder
    return finalTable
end

------------------------------------------------------
------------------------------------------------------

function Initialize()
    dofile(SKIN:GetVariable('@')..[[Scripts\Common.lua]])
    InitiateConfigs()
    UpdatePanel()
end

oldActive = 0
function Update()
    local newActive = GetActive()
    if (newActive ~= oldActive) then
        oldActive = newActive
        SKIN:Bang('!UpdateMeasure', 'RainConfigs', SKIN:GetVariable('ROOTCONFIG') .. [[\SidePanel]])
        SKIN:Bang('!UpdateMeter', 'Load')
        SKIN:Bang('!Redraw')
    end
end

------------------------------------------------------
------------------------------------------------------

function UpdatePanel()
    SKIN:Bang('!UpdateMeter', '*')
    SKIN:Bang('!Redraw')
end

function GetData(property)
    local prop = currentmetadata[property]
    if (property:lower() == 'preview') then
        prop = prop:lower():gsub('#@#', currentmetadata.rootpath .. [[@Resources\]]):gsub('#rootconfigpath#', currentmetadata.rootpath)
        prop = prop:gsub('%{resources%}', SKIN:GetVariable('@'))
        prop = SKIN:ReplaceVariables(prop)
    elseif property:lower() == 'information' then
        prop = prop:gsub('%|%|', '\n ')
    end
    return prop
end

function GetActive()
    if currentmetadata.root == "" then return 0 end
    if SKIN:ReplaceVariables('[&ConfigActive:IsActive(' .. currentmetadata.root .. ')]') == '1' then
        if SKIN:ReplaceVariables('[&ConfigActive:ConfigVariantName(' .. currentmetadata.root .. ')]') == currentmetadata.name then
            return 1
        end
    end
    return 0
end

function Toggle()
    if currentmetadata.root == "" then return end
    if GetActive() == 0 then
        SKIN:Bang('!ActivateConfig', currentmetadata.root, currentmetadata.name)
    else
        SKIN:Bang('!DeactivateConfig', currentmetadata.root)
    end
    SKIN:Bang('!UpdateMeter', 'Load')
    SKIN:Bang('!Redraw')
end

function Edit()
    if currentmetadata.name ~= "" then
        SKIN:Bang('!EditSkin', currentmetadata.root, currentmetadata.name)
    end
end