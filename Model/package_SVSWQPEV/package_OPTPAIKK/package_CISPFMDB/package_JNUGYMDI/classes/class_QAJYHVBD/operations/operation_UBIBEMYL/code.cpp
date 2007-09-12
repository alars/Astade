wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

wxString suffix;
if(aFileName.GetPath() == myFileName.GetPath())
	suffix = "_copied";

theConfig.Write("Astade/Name",myConfig->Read("Astade/Name") + suffix);
theConfig.Write("Astade/Type", myConfig->Read("Astade/Type"));
theConfig.Write("Astade/Declaration", myConfig->Read("Astade/Declaration"));
theConfig.Write("Astade/Description", myConfig->Read("Astade/Description"));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
{
	int ret = theRevisionControl->Add(aFileName);
	wxArrayString output = theRevisionControl->GetOutput();

	if (ret!=0)
	{
		wxString message;
		for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
	}
}

return aFileName;