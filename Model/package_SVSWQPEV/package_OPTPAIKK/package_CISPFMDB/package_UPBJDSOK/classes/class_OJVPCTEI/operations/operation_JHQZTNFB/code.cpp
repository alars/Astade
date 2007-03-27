AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

wxFileName toFileName(parentPath.GetPath(), myFileName.GetFullName());

int ret = theRevisionControl->Move(myFileName, toFileName);

wxArrayString output = theRevisionControl->GetOutput();
wxString message;

for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";

return (0 == ret);