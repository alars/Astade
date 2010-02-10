AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

wxFileName toFileName(parentPath.GetPath(), myFileName.GetFullName());

int ret = theRevisionControl->Move(myFileName, toFileName);
return ret == 0;
