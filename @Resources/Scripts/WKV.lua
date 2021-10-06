print(currentmetadata.preview)

function WriteKeyValue(section, key, value, filePath)
    local file=assert(io.open(filePath, 'r'), 'File path invalid!')
    file:close()
    local content = ReadIni(filePath)
    if table.contains(content.SectionOrder, section, 'value') then
        if table.contains(content.KeyOrder[section], key, 'value') then
            content.INI[section][key] = value
        else
            table.insert(content.KeyOrder[section], key)
            content.INI[section][key] = value
        end
    else
        table.insert(content.SectionOrder, section)
        content.INI[section] = {}
        content.KeyOrder[section]={}
        table.insert(content.KeyOrder[section], key)
        content.INI[section][key] = value
    end
    WriteIni(content, filePath)
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

function WriteIni(table, outfile)
    local outTable = {}
    for _, v in ipairs(table.SectionOrder) do
        table.insert(outTable, '['..v..']')
        for _, V in ipairs(table.KeyOrder[v]) do
            table.insert(outTable, V..'='..table.INI[v][V])
        end
    end
    local file = io.open(outfile, 'w')
    file:write(table.concat(outTable, '\n'))
    file:close()
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