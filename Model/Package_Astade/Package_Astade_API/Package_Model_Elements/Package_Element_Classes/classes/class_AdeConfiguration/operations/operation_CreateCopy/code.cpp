wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());     //create .ini file and for copying .ini file from source

wxString suffix;
wxFileName testFileName(myFileName);
testFileName.RemoveLastDir();
if (testFileName.GetPath() == parentPath.GetPath())
	suffix = wxS("_copied");

theConfig.Write(wxS("Astade/Name"), myConfig->Read(wxS("Astade/Name")) + suffix);
theConfig.Write(wxS("Astade/Type"), myConfig->Read(wxS("Astade/Type")));
theConfig.Write(wxS("Astade/Description"), myConfig->Read(wxS("Astade/Description")));
theConfig.Flush(); // permanentely writes all changes

/* Copy contents of source to destination directory */

wxFileName destination;
destination.AssignDir(aFileName.GetPath());   // I need only directory path not with a file

for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();  //Create right object with wxFileName from iterator it.
	anElement->CreateCopy(destination);
	delete anElement;
}

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
