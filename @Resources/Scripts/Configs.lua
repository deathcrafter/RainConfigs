config={}

metaconfig={ 
    __index = {
        index = 0,
        name = '',
        ini = false,
        root = '',
        level = 0,
        active = 0,
        iniActive = false,
        activeIni = '', 
        configsActive = false,
        open = 0
    },
    __call = function (table)
        if not table.ini then
            table.open=1-table.open
            SetMeters()
        else
            SKIN:Bang('!CommandMeasure', 'Meta', 'configArray['..table.index..']()', SKIN:ReplaceVariables([[#ROOTCONFIG#\MainPanel]]))
        end
    end
}

setmetatable(config,metaconfig)

function config:new()
    local conf = {}
    setmetatable(conf, metaconfig)
    return conf
end

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
                    -- conf.metadata = ReadMetaTable(SKIN:GetVariable('SKINSPATH')..conf.root..[[\]]..conf.name)
                    --print(conf.metadata.author)
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