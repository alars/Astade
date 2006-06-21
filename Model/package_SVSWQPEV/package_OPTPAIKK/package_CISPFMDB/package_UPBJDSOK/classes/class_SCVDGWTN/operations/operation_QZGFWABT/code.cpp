AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

int ret1 = theRevisionControl->Delete(myFileName);
int ret2 = theRevisionControl->Delete(thePartnerFileName);

wxArrayString output = theRevisionControl->GetOutput();
wxString message;

for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";

if ((ret1!=0)||(ret2!=0))
	wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);