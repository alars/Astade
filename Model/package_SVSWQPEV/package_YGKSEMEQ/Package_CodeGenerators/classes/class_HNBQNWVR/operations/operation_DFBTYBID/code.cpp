wxString str = aString;

if (str.Find("\"") != wxNOT_FOUND)
	str.Remove(str.Find("\""));

str.Replace("\t"," ");

str = "  " + str;

if ((traceLevel==0) && ((str.Find(" RETURN ") != wxNOT_FOUND) || (str.Find(" RETURN(") != wxNOT_FOUND))) 
	return "#error Don't use \"RETURN\" in \"C\" code with tracelevel 0 //" + aString;
else
if ((traceLevel==0) && (str.Find(" voidRETURN ") != wxNOT_FOUND))
	return "#error Don't use \"voidRETURN\" in \"C\" code with tracelevel 0 //" + aString;
else
if ((traceLevel!=0) && ((str.Find(" return ") != wxNOT_FOUND) || (str.Find(" return(") != wxNOT_FOUND))) 
	return "#error Don't use \"return\" in instrumented \"C\" code //" + aString;
else
	return aString;
