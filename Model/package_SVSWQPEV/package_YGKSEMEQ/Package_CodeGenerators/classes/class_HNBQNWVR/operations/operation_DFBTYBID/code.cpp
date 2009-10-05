if (traceLevel==0)
	return aString;
	
wxString str = aString;

if (str.Find("\"") != wxNOT_FOUND)
	str.Remove(str.Find("\""));

str.Replace("\t"," ");

str = "  " + str;

if ((str.Find(" return ") != wxNOT_FOUND) || (str.Find(" return(") != wxNOT_FOUND)) 
	return "#error Don't use \"return\" in instrumented \"C\" code //" + aString;
else
	return aString;
