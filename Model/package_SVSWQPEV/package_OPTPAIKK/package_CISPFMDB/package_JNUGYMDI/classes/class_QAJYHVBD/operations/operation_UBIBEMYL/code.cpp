wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

theConfig.Write("Astade/Name",copyConfig.Read("Astade/Name"));
theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Write("Astade/Declaration", copyConfig.Read("Astade/Declaration"));
theConfig.Write("Astade/Description", copyConfig.Read("Astade/Description"));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
{
	int ret = theRevisionControl->Add(aFileName);
	wxArrayString output = theRevisionControl->GetOutput();

	if (ret!=0)
	{
		wxString message;
		for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
		wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
	}
}

return aFileName;