wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());     //create .ini file and for copying .ini file from source

wxString suffix;
wxFileName testFileName(myFileName);
testFileName.RemoveLastDir();
if (testFileName.GetPath() == parentPath.GetPath())
	suffix = "_copied";

theConfig.Write("Astade/Name", myConfig->Read("Astade/Name") + suffix);
theConfig.Write("Astade/Type", myConfig->Read("Astade/Type"));
theConfig.Write("Astade/Description", myConfig->Read("Astade/Description"));
theConfig.Flush(); // permanentely writes all changes

/* Copy contents of source to destination directory */

wxFileName destination;
destination.AssignDir(aFileName.GetPath());   // I need only directory path not with a file

for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();  //Create right object with xwFileName from iterator it.
	anElement->CreateCopy(destination);
	delete anElement;
}

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
if (theRevisionControl->IsAddSupported())
{
	theRevisionControl->Add(aFileName);
	wxArrayString output = theRevisionControl->GetOutput();
}

return aFileName;
