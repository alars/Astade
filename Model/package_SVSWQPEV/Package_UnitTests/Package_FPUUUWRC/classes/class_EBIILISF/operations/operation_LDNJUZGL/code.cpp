if (!parseResult)
	return wxEmptyString;

return regEx.GetMatch(myParseText,2).Trim(true).Trim(false);