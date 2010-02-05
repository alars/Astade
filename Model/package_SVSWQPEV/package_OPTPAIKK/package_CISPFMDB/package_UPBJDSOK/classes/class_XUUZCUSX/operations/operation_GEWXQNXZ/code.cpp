AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

wxArrayString dirs = myFileName.GetDirs();
wxFileName toFileName(parentPath);
toFileName.AppendDir(dirs.Last());

int ret = theRevisionControl->Move(myFileName.GetPath(wxPATH_GET_SEPARATOR), toFileName.GetPath(wxPATH_GET_SEPARATOR));

return ret == 0;
