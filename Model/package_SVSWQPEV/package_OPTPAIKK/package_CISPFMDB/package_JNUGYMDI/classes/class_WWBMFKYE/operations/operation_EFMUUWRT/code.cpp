wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());     //create .ini file and for copying .ini file from source
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());   //source .ini file myFileName is in the AdeModelElement

wxString suffix("_Copied");
theConfig.Write("Astade/Name", copyConfig.Read("Astade/Name") + suffix);
theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Write("Astade/Description", copyConfig.Read("Astade/Description"));

if(GetIsLibClass())
{
	theConfig.Write("Astade/LibClass", copyConfig.Read("Astade/LibClass"));
	theConfig.Write("Astade/ClassInclude", copyConfig.Read("Astade/ClassInclude"));
} else
	theConfig.Write("Astade/AdditionalClasses", copyConfig.Read("Astade/AdditionalClasses"));


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
		wxMessageBox(message, "Operation failed", wxOK | wxICON_ERROR);
	}
}

return aFileName;
