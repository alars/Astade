wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());     //create .ini file and for copying .ini file from source
wxFileConfig copyConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());   //source .ini file myFileName is in the AdeModelElement

theConfig.Write("Astade/Name", copyConfig.Read("Astade/Name"));
theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));


/*                                      */
/* Copying all from class directory		*/
/*                                      */

wxFileName destination;
destination.AssignDir(aFileName.GetPath());   // I need only directory path not with a file

AdeElementIterator it;
for(it = begin(); it != end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();  //Create right object with xwFileName from iterator it.
	aElement->CreateCopy(destination);
	delete aElement;
}

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
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
