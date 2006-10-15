wxFileConfig myConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
wxString name = myConfig.Read("Astade/Name");  //Getting directory name from source.

//wxMessageBox(name);

parentPath.AppendDir(name);
if(parentPath.Mkdir(parentPath.GetPath())) //I want to copy everything in this path.
{
    AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
	if (theRevisionControl->IsAddSupported())
	{
		int ret = theRevisionControl->Add(parentPath); //Add new directory to SVN
		wxArrayString output = theRevisionControl->GetOutput();

		if (ret!=0)
		{
			wxString message;
			for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
			wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
		}
	}
}
else
	wxMessageBox("Something went wrong creating directory, " + parentPath.GetPath());

wxFileName aFileName = parentPath;
aFileName.SetFullName("ModelNode.ini");  //Set ModelNode.ini file in copied directory.

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());     //create .ini file and for copying .ini file from source
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());   //source .ini file myFileName is in the AdeModelElement

theConfig.Write("Astade/Name",copyConfig.Read("Astade/Name"));
theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Flush(); // permanentely writes all changes

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

return aFileName;
