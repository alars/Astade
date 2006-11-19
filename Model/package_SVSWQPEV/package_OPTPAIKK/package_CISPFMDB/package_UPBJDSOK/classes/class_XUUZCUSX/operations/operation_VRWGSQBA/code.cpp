wxFileConfig myConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
wxString name = myConfig.Read("Astade/Name");  //Getting directory name from source.
int type = myConfig.Read("Astade/Type",long(0));       //Getting element type
wxFileName aFileName = CreateNewElement(parentPath, name, type, false); //Creating new element for copying.

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());     //create .ini file and for copying .ini file from source
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());   //source .ini file myFileName is in the AdeModelElement

theConfig.Write("Astade/Name",copyConfig.Read("Astade/Name"));
theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Flush(); // permanentely writes all changes

/*                                     	    */
/* Copying all from class the directory		*/
/*                                          */

wxFileName destination;
destination.AssignDir(aFileName.GetPath());   // I need only directory path not with a file

AdeElementIterator it;
for(it = begin(); it != end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();  //Create right object with xwFileName from iterator it.
	aElement->CreateCopy(destination);  // Copying directory elements from the source "class" directory to destination.
	delete aElement;
}

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
if (theRevisionControl->IsAddSupported())
{
    //wxMessageBox(aFileName.GetFullPath());
	int ret = theRevisionControl->Add(aFileName); //Add new copied .ini file to SVN
	wxArrayString output = theRevisionControl->GetOutput();

	if (ret!=0)
	{
		wxString message;
		for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
		wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
	}
}

return aFileName;
