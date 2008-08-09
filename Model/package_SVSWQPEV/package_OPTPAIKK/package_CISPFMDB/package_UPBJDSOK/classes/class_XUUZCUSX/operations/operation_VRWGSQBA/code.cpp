// test if the destination path is our own subdirectory
wxFileName testRelativity(parentPath);
testRelativity.MakeRelativeTo(myFileName.GetPath());
if (!testRelativity.GetPath().StartsWith(".."))
	return wxFileName();

wxFileConfig myConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
wxString name = myConfig.Read("Astade/Name");  //Get directory name from source.
int type = myConfig.Read("Astade/Type",long(0));       //Get element type
wxFileName aFileName = CreateNewElement(parentPath, name, type, false); //Create new element for copying.

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());     //create .ini file and for copying .ini file from source

wxString suffix;
if (aFileName.GetPath() == myFileName.GetPath())
	suffix = "_copied";

theConfig.Write("Astade/Name", myConfig.Read("Astade/Name") + suffix);
theConfig.Write("Astade/Type", myConfig.Read("Astade/Type"));
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
{
	theRevisionControl->Add(aFileName);
	wxArrayString output = theRevisionControl->GetOutput();
}

return aFileName;
