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
    if not type then type = 'value' end
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