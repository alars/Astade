wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString suffix;
if(aFileName.GetPath() == myFileName.GetPath())
	suffix = "_copied";

theConfig.Write("Astade/Name", copyConfig.Read("Astade/Name") + suffix);
theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Write("Astade/CodingType", copyConfig.Read("Astade/CodingType"));
theConfig.Write("Astade/Description", copyConfig.Read("Astade/Description"));
theConfig.Write("Astade/Static",  copyConfig.Read("Astade/Static"));
theConfig.Write("Astade/Const",  copyConfig.Read("Astade/Const"));
theConfig.Write("Astade/Default",  copyConfig.Read("Astade/Default"));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
{
	theRevisionControl->Add(aFileName);
	wxArrayString output = theRevisionControl->GetOutput();
}

return aFileName;