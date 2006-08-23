wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
return wxString::Format(theConfig.Read("Astade/Declaration"), GetName().c_str());
