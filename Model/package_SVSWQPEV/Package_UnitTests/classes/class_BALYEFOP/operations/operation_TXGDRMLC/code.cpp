wxFileName aFileName = wxFileName(fileName->GetValue());
wxFileName toFileName = wxFileName(wxFileSelector("Move File to...", aFileName.GetPath(), aFileName.GetFullName(), "*.*", "Alle Dateien (*.*)|*.*", wxSAVE));
AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
theRevisionControl->Move(aFileName, toFileName);
wxArrayString output = theRevisionControl->GetOutput();
wxString message;
for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
wxMessageBox(message, "RevisionControl output");
