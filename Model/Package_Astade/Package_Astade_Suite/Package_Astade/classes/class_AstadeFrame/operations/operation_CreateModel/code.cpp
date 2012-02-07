//~~ void CreateModel(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxString workspace(wxDirSelector(wxS("Create Model"), theConfig->Read(wxS("TreeView/ModelPath")), wxDD_DEFAULT_STYLE));
if (workspace.empty())
	return;

wxDir dir(workspace);
if (dir.HasFiles() || dir.HasSubDirs())
{
	wxMessageBox(wxS("The new model directory is not empty!"));
	return;
}

wxFileName filename(workspace);
theConfig->Write(wxS("TreeView/ModelPath"), filename.GetFullPath());
AddToRecentList(filename);
theConfig->Write(wxS("TreeView/ActiveComponent"), wxS("none"));
theConfig->Flush();

AstadeTree* oldTree = myTree;
myTree =  new AstadeTree(this);
AstadeTreeItemBase::SetOurTree(*myTree);
delete oldTree;

int x, y;
GetSize(&x, &y);
SetSize(x - 1, y);
SetSize(x, y);
