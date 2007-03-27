wxFileName theFileName(myFileName);
theFileName.SetFullName("code.cpp");

if (!wxFile::Exists(theFileName.GetFullPath().c_str()))
{
	wxFile(theFileName.GetFullPath().c_str(),wxFile::write);

	AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
	if (theRevisionControl->IsAddSupported())
	{
		int ret = theRevisionControl->Add(theFileName);
		wxArrayString output = theRevisionControl->GetOutput();

		if (ret!=0)
		{
			wxString message;
			for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
		}
	}
}