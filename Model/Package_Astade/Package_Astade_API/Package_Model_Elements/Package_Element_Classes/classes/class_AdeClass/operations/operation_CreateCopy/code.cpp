//~~ wxFileName CreateCopy(wxFileName parentPath) [AdeClass] ~~
wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());     //create .ini file and for copying .ini file from source

wxString suffix;
wxFileName testFileName(myFileName);
testFileName.RemoveLastDir();
if (testFileName.GetPath() == parentPath.GetPath())
	suffix = wxS("_copied");

theConfig.Write(wxS("Astade/Name"), myConfig->Read(wxS("Astade/Name")) + suffix);
theConfig.Write(wxS("Astade/Type"), myConfig->Read(wxS("Astade/Type")));
theConfig.Write(wxS("Astade/Description"), myConfig->Read(wxS("Astade/Description")));

if (IsManualClass())
{
	theConfig.Write(wxS("Astade/ManualClass"), myConfig->Read(wxS("Astade/ManualClass")));
}

if (IsLibClass())
{
	theConfig.Write(wxS("Astade/LibClass"), myConfig->Read(wxS("Astade/LibClass")));
	theConfig.Write(wxS("Astade/ClassInclude"), myConfig->Read(wxS("Astade/ClassInclude")));
}
else
{
	theConfig.Write(wxS("Astade/AdditionalClasses"), myConfig->Read(wxS("Astade/AdditionalClasses")));
	theConfig.Write(wxS("Astade/CCoded"), myConfig->Read(wxS("Astade/CCoded")));
	theConfig.Write(wxS("Astade/Deprecated"), myConfig->Read(wxS("Astade/Deprecated")));
}

/*                                      */
/* Copying all from class directory		*/
/*                                      */

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
	theRevisionControl->Add(aFileName);

return aFileName;
