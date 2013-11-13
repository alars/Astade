//~~ wxFileName CreateCopy(wxFileName parentPath) [AdeStatechart] ~~

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
theConfig.Write(wxS("Astade/InitialState"), myConfig->Read(wxS("Astade/InitialState")));
theConfig.Write(wxS("Astade/Action1"), myConfig->Read(wxS("Astade/Action1")));
theConfig.Write(wxS("Astade/Action2"), myConfig->Read(wxS("Astade/Action2")));
theConfig.Write(wxS("Astade/Action3"), myConfig->Read(wxS("Astade/Action3")));
theConfig.Write(wxS("Astade/Action4"), myConfig->Read(wxS("Astade/Action4")));
theConfig.Write(wxS("Astade/EventType"), myConfig->Read(wxS("Astade/EventType")));
theConfig.Write(wxS("Astade/CoderSuffix"), myConfig->Read(wxS("Astade/CoderSuffix")));

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
