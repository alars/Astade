wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Write("Astade/Description", copyConfig.Read("Astade/Description"));
theConfig.Write("Astade/Virtual", copyConfig.Read("Astade/Virtual"));

wxFileName codeSource = myFileName;
wxFileName codeDest = aFileName;

codeSource.SetFullName("code.cpp");
codeDest.SetFullName("code.cpp");

wxCopyFile(codeSource.GetFullPath(),codeDest.GetFullPath());

return aFileName;