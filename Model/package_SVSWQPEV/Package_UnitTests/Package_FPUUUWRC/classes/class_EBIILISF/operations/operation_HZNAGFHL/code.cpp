if (!parseResult)
	return wxEmptyString;

return regEx.GetMatch(myParseText,1).Trim(true).Trim(false);