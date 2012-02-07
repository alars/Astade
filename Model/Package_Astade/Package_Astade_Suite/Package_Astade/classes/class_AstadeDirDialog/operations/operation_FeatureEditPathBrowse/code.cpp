//~~ void FeatureEditPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/FeatureEdit")));

const wxString& dir = wxFileSelector(wxS("Set Feature editor"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);
wxFileName filename(dir);

if (!dir.empty())
	featureEditPathTextControl->SetValue(filename.GetFullPath());

