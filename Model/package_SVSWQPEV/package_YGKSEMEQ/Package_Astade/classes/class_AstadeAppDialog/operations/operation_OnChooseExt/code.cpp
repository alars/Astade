const wxString& aFile = wxFileSelector("Select a file to take the filetype from", "", "","*.*", "All files (*.*)|*.*", 0, this);
if( !aFile.IsEmpty() ) 
{
	txtExt->SetValue(wxFileName(aFile).GetExt());
}