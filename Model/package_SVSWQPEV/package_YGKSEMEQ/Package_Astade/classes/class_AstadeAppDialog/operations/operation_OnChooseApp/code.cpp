wxFileName theFilename = wxFileName(txtApp->GetValue());

const wxString& aFile = wxFileSelector("Select the application executable", theFilename.GetPath(), theFilename.GetFullName(),"*.*", "All files (*.*)|*.*", 0, this);
if( !aFile.IsEmpty() ) 
{
	txtApp->SetValue(aFile);
}