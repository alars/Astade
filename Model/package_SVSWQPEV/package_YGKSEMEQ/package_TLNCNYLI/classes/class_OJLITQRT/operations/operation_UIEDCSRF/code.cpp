wxConfigBase* theConfig = wxConfigBase::Get();

wxRegEx regEx(theConfig->Read("TreeView/RegEx/identifyExpression"));
if (!regEx.IsValid())
{ // regular expression has syntax error
/*	wxLogError("The regular expression %s has a syntax error",
		theConfig->Read("TreeView/RegEx/identifyExpression").c_str());
*/
	return false;
}


if (regEx.Matches(parseLine.c_str()))
	return true;
else
	return false;