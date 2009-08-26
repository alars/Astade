wxString aString = myConfig->Read("Astade/Declaration");
aString.Replace("%s",GetName());
return aString;
