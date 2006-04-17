wxFileName aFileName = wxFileName(fileName->GetValue());
AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
theRevisionControl->Delete(aFileName);
wxArrayString output = theRevisionControl->GetOutput();
wxString message;
for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
wxMessageBox(message, "RevisionControl output");