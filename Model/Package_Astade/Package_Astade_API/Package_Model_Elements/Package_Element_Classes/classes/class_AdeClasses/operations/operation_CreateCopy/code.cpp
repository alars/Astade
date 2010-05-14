wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());     //create .ini file and for copying .ini file from source

theConfig.Write(wxS("Astade/Name"), myConfig->Read(wxS("Astade/Name")));
theConfig.Write(wxS("Astade/Type"), myConfig->Read(wxS("Astade/Type")));

/*                                      */
/* Copying all from class directory		*/
/*                                      */

wxFileName destination;
destination.AssignDir(aFileName.GetPath());   // I need only directory path not with a file

for(AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();  //Create right object with xwFileName from iterator it.
	anElement->CreateCopy(destination);
	delete anElement;
}

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
