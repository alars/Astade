wxFileName theFilename = wxFileName(txtIcon->GetValue());

const wxString& aFile = wxFileSelector("Select the icon", theFilename.GetPath(), theFilename.GetFullName(),"*.*", "All icon files|*.ico,*.bmp,*.png,*.jpg,*.gif,*.xpm,*.xbm|All files (*.*)|*.*", 0, this);
if( !aFile.IsEmpty() ) 
{
	txtIcon->SetValue(aFile);
}