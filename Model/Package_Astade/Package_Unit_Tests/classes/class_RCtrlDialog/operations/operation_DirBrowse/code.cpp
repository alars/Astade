wxFileName theFileName(fileName->GetValue());

const wxString& dir = wxDirSelector("Select directory", theFileName.GetPath(), 0, wxDefaultPosition, this);

wxFileName filename;
filename.AssignDir(dir);

if (!dir.empty())
	fileName->SetValue(filename.GetFullPath());
