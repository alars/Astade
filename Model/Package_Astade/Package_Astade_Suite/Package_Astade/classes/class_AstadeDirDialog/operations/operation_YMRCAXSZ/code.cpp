//~~ void CompositeStructurePathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~
wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/CompositeStructureViewPath"));

const wxString& dir = wxFileSelector("Set Composit structure drawer path",theFileName.GetPath(),theFileName.GetFullName(),"","*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
{
	compositeStructurePathTextControl->SetValue(filename.GetFullPath());
}

