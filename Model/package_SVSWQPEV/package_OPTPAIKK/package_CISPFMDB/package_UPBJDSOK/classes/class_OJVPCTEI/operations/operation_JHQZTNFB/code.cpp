AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

wxFileName toFileName(parentPath.GetPath(), myFileName.GetFullName());

int ret = theRevisionControl->Move(myFileName, toFileName);

wxArrayString output = theRevisionControl->GetOutput();
wxString message;

for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";

if (ret!=0)
	wxMessageBox(message, "Operation failed", wxOK | wxICON_ERROR);

return toFileName;