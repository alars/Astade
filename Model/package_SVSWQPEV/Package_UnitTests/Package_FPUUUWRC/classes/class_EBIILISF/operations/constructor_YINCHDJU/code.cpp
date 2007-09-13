if (!regEx.IsValid())
	return;

parseText += "\x0"; // to find the end

if (!regEx.Matches(parseText))
	return;

parseResult = true;