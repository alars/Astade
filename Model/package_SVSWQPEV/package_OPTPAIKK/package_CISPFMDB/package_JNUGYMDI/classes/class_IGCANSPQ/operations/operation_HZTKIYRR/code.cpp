wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

theConfig.Write("Astade/Name",copyConfig.Read("Astade/Name"));
theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Write("Astade/CodingType", copyConfig.Read("Astade/CodingType"));
theConfig.Write("Astade/Description", copyConfig.Read("Astade/Description"));
theConfig.Write("Astade/Virtual", copyConfig.Read("Astade/Virtual"));
theConfig.Write("Astade/Abstract",  copyConfig.Read("Astade/Abstract"));
theConfig.Write("Astade/Static",  copyConfig.Read("Astade/Static"));
theConfig.Write("Astade/Const",  copyConfig.Read("Astade/Const"));

if (GetHasParameters())
{
	wxFileName parametersFileName = AdeParameters::CreateNewElement(aFileName.GetFullPath());
}

return aFileName;