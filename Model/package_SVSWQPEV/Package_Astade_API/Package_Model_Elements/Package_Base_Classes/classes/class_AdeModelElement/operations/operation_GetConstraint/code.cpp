wxString aString = myConfig->Read("Astade/Constraint");
aString.Replace("%s",GetName());
return aString;
