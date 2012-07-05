//~~ void Move(wxCommandEvent& event) [RCtrlDialog] ~~

wxFileName aFileName = wxFileName(fileName->GetValue());
wxFileName toFileName = wxFileName(wxFileSelector(wxS("Move File to..."), aFileName.GetPath(), aFileName.GetFullName(), wxS("*.*"), wxS("All files (*.*)|*.*"), wxFD_SAVE));
AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

int ret = theRevisionControl->Move(aFileName, toFileName);

wxArrayString output = theRevisionControl->GetOutput();
wxString message;
for (size_t i = 0; i < output.GetCount(); i++)
	message += output[i] + wxS("\n");

if (ret == 0)
	wxMessageBox(message, wxS("Operation Successful"));
else
	wxMessageBox(message, wxS("Operation failed"), wxOK | wxICON_ERROR);
