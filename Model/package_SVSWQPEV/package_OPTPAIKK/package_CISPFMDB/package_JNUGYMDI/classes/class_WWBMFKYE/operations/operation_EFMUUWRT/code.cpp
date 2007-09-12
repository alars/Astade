wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());     //create .ini file and for copying .ini file from source

wxString suffix;
wxFileName testFileName(myFileName);
testFileName.RemoveLastDir();
if(testFileName.GetPath() == parentPath.GetPath())
	suffix = "_copied";

theConfig.Write("Astade/Name", myConfig->Read("Astade/Name") + suffix);
theConfig.Write("Astade/Type", myConfig->Read("Astade/Type"));
theConfig.Write("Astade/Description", myConfig->Read("Astade/Description"));

if(GetIsLibClass())
{
	theConfig.Write("Astade/LibClass", myConfig->Read("Astade/LibClass"));
	theConfig.Write("Astade/ClassInclude", myConfig->Read("Astade/ClassInclude"));
} else
	theConfig.Write("Astade/AdditionalClasses", myConfig->Read("Astade/AdditionalClasses"));


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
	theRevisionControl->Add(aFileName);
	wxArrayString output = theRevisionControl->GetOutput();
}

return aFileName;
