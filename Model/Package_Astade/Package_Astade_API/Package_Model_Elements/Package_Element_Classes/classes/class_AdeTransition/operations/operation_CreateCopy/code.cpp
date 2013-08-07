//~~ wxFileName CreateCopy(wxFileName parentPath) [AdeTransition] ~~
wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

theConfig.Write(wxS("Astade/TransitionType"), myConfig->Read(wxS("Astade/TransitionType")));
theConfig.Write(wxS("Astade/Description"), myConfig->Read(wxS("Astade/Description")));
theConfig.Write(wxS("Astade/Action1"), myConfig->Read(wxS("Astade/Action1")));
theConfig.Write(wxS("Astade/Action2"), myConfig->Read(wxS("Astade/Action2")));
theConfig.Write(wxS("Astade/Action3"), myConfig->Read(wxS("Astade/Action3")));
theConfig.Write(wxS("Astade/Action4"), myConfig->Read(wxS("Astade/Action4")));
theConfig.Write(wxS("Astade/DestinationState"), myConfig->Read(wxS("Astade/DestinationState")));
theConfig.Write(wxS("Astade/Guard"), myConfig->Read(wxS("Astade/Guard")));
theConfig.Write(wxS("Astade/Trigger"), myConfig->Read(wxS("Astade/Trigger")));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
