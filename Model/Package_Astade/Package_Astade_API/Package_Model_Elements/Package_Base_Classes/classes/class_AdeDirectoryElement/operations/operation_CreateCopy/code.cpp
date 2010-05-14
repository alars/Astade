// test if the destination path is our own subdirectory
wxFileName testRelativity(parentPath);
testRelativity.MakeRelativeTo(myFileName.GetPath());
if (!testRelativity.GetPath().StartsWith(wxS("..")))
	return wxFileName();

wxFileConfig myConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
wxString name = myConfig.Read(wxS("Astade/Name"));  //Get directory name from source.
int type = myConfig.Read(wxS("Astade/Type"), 0L);       //Get element type
wxFileName aFileName = CreateNewElement(parentPath, name, type, false); //Create new element for copying.

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());     //create .ini file and for copying .ini file from source

wxString suffix;
if (aFileName.GetPath() == myFileName.GetPath())
	suffix = wxS("_copied");

theConfig.Write(wxS("Astade/Name"), myConfig.Read(wxS("Astade/Name")) + suffix);
theConfig.Write(wxS("Astade/Type"), myConfig.Read(wxS("Astade/Type")));
theConfig.Flush(); // permanentely writes all changes

/* Copy contents of source to destination directory */

wxFileName destination;
destination.AssignDir(aFileName.GetPath());   // I need only directory path not with a file

for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();  //Create right object with wxFileName from iterator it.
	anElement->CreateCopy(destination);  // Copy directory elements from the source "class" directory to destination.
	delete anElement;
}

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
