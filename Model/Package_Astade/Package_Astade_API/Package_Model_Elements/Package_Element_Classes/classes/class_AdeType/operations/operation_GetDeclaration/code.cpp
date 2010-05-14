wxString aString = myConfig->Read(wxS("Astade/Declaration"));
aString.Replace(wxS("%s"), GetName());
return aString;
