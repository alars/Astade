AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

wxArrayString dirs = myFileName.GetDirs();	
wxFileName toFileName(parentPath);
toFileName.AppendDir(dirs.Last());

int ret = theRevisionControl->Move(myFileName.GetPath(wxPATH_GET_SEPARATOR), toFileName.GetPath(wxPATH_GET_SEPARATOR));

wxArrayString output = theRevisionControl->GetOutput();
wxString message;

for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";

if (ret!=0)
	wxMessageBox(message, "Operation failed", wxOK | wxICON_ERROR);

return (0 == ret);