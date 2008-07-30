wxConfigBase* theConfig = wxConfigBase::Get();

wxString workspace = wxDirSelector("Select Astade Workspace", theConfig->Read("TreeView/ModelPath"), wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

if(workspace.empty()) return;

//input dialog to get input
wxString newModelName = wxGetTextFromUser("Enter a name of the New Astade Model");

if(newModelName.empty()){
 return;
}

const wxString& dir = workspace + "/" + newModelName;

//Create dir and default Model dir
if(wxFileName::DirExists(dir)){
	wxMessageBox("The new model directory name already exists");
	return;
}

const wxString& newFullModelName = dir + "/Model";

wxFileName::Mkdir(newFullModelName, 0777, wxPATH_MKDIR_FULL);

wxFileName filename(newFullModelName);


if (!newModelName.empty())
{
	wxConfigBase* theConfig = wxConfigBase::Get();
	theConfig->Write("TreeView/ModelPath", filename.GetFullPath());
	AddToRecentList(filename);
	theConfig->Write("TreeView/ActiveComponent", "none");
	theConfig->Flush();
	delete myTree;
	myTree =  new AstadeTree(this);

	int x,y;
	GetSize(&x, &y);
	SetSize(x-1, y);
	SetSize(x, y);
}
