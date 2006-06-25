AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

int ret = theRevisionControl->Delete(myFileName);
wxArrayString output = theRevisionControl->GetOutput();
wxString message;

for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";

if (ret!=0)
	wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);