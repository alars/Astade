//~~ void Delete() [AdeRelationBase] ~~

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

theRevisionControl->Delete(myFileName);
if (thePartnerFileName.FileExists())
	theRevisionControl->Delete(thePartnerFileName);
