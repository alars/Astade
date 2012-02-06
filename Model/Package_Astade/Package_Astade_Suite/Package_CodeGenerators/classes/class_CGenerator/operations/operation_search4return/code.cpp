//~~ wxString search4return(const wxString& aString, int traceLevel) [CGenerator] ~~

wxString str = aString;

if (str.Find(wxS("\"")) != wxNOT_FOUND)
	str.Remove(str.Find(wxS("\"")));

str.Replace(wxS("\t"), wxS(" "));

str = wxS("  ") + str;

if (traceLevel == 0 && (str.Find(wxS(" CRETURN ")) != wxNOT_FOUND || str.Find(wxS(" CRETURN(")) != wxNOT_FOUND))
	return wxS("#error Don't use \"CRETURN\" in \"C\" code with tracelevel 0 //") + aString;
else if (traceLevel == 0 && str.Find(wxS(" voidRETURN ")) != wxNOT_FOUND)
	return wxS("#error Don't use \"voidRETURN\" in \"C\" code with tracelevel 0 //") + aString;
else if (traceLevel != 0 && (str.Find(wxS(" return ")) != wxNOT_FOUND || str.Find(wxS(" return;")) != wxNOT_FOUND || str.Find(wxS(" return(")) != wxNOT_FOUND))
	return wxS("#error Don't use \"return\" in instrumented \"C\" code //") + aString;
else
	return aString;
