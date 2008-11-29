wxConfigBase* theConfig = wxConfigBase::Get();
wxString workspace(wxDirSelector("Create Model", theConfig->Read("TreeView/ModelPath"), wxDD_DEFAULT_STYLE));
if (workspace.empty())
	return;

wxDir dir(workspace);
if (dir.HasFiles() || dir.HasSubDirs())
{
	wxMessageBox("The new model directory is not empty!");
	return;
}

wxFileName filename(workspace);
theConfig->Write("TreeView/ModelPath", filename.GetFullPath());
AddToRecentList(filename);
theConfig->Write("TreeView/ActiveComponent", "none");
theConfig->Flush();

AstadeTree* oldTree = myTree;
myTree =  new AstadeTree(this);
AstadeTreeItemBase::SetOurTree(*myTree);
delete oldTree;

int x,y;
GetSize(&x, &y);
SetSize(x-1, y);
SetSize(x, y);
