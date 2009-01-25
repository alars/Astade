wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

wxString suffix;
if(aFileName.GetPath() == myFileName.GetPath())
	suffix = "_copied";

theConfig.Write("Astade/Name",myConfig->Read("Astade/Name") + suffix);
theConfig.Write("Astade/CodingType", myConfig->Read("Astade/CodingType"));
theConfig.Write("Astade/Description", myConfig->Read("Astade/Description"));
theConfig.Write("Astade/Default", myConfig->Read("Astade/Default"));
theConfig.Write("Astade/Type", myConfig->Read("Astade/Type")); // Type must be copied, because of the order information coded in the type
theConfig.Write("Astade/InputParameter", myConfig->Read("Astade/InputParameter"));
theConfig.Write("Astade/OutputParameter", myConfig->Read("Astade/OutputParameter"));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
{
	theRevisionControl->Add(aFileName);
	wxArrayString output = theRevisionControl->GetOutput();
}

return aFileName;