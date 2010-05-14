wxString aString = myConfig->Read(wxS("Astade/Constraint"));
aString.Replace(wxS("%s"), GetName());
return aString;
