//~~ void CCoderPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~
wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/CCoder"));

const wxString& dir = wxFileSelector("Set C Coder",theFileName.GetPath(),theFileName.GetFullName(),"","*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
{
	ccoderPathTextControl->SetValue(filename.GetFullPath());
}

