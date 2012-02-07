//~~ AstadeTree(wxWindow* parent) [AstadeTree] ~~

wxArrayString names;
names.Add(wxS("model"));

AstadeFile::UpdateUserAppIcons();
SetImageList(AstadeIcons::Instance());
wxTreeItemId myRootItem = AddRoot(wxS("model"), AstadeIcons::Instance()->GetIconIndex(names));

wxConfigBase* theConfig = wxConfigBase::Get();
wxString modelPath = theConfig->Read(wxS("TreeView/ModelPath"));

wxFileName modelDir;
modelDir.AssignDir(modelPath);
modelDir.MakeAbsolute();
wxFileName::SetCwd(modelDir.GetPath());

AdeModel* aModel = new AdeModel(modelDir);

// Check whether the model is newer (modified by a newer version of Astade)
int saveVersion = aModel->GetSaveVersion();

if (saveVersion > 4) // Model is not compatible with this Astade version
{
    if (wxMessageBox(wxS("This model seems to have been modified by a newer version of Astade. If you continue, things might not work propperly.\nYou had better get the newest version at http://www.astade.de\n\nDo you really want to try working with this Astade version (on your own risk)?"),
            wxS("Model has newer Version!"), wxICON_QUESTION  | wxYES_NO) == wxNO)
    {
        DeleteAllItems();
        return;
    }
}

if (saveVersion < 4) // if we continue here, we have at least save version 3
{
    aModel->SetSaveVersion(4);
}

SetItemData(myRootItem, AstadeTreeItemBase::CreateNewElement(aModel));

AdeGUIDCache::Instance()->Load(*aModel);

AdeRevisionControlBase* aRevisionControl;
if (aModel->GetRepository() == wxS("SVN"))
{
	if (!wxFileName::DirExists(wxS(".svn")))
		aRevisionControl = new AdeRevisionControlGIT;
	else
		aRevisionControl = new AdeRevisionControlSVN;
}
else if (aModel->GetRepository() == wxS("git"))
	aRevisionControl = new AdeRevisionControlGIT;
else if (aModel->GetRepository() == wxS("CVS"))
	aRevisionControl = new AdeRevisionControlCVS;
else if (aModel->GetRepository() == wxS("MKS"))
	aRevisionControl = new AdeRevisionControlMKS(aModel->GetRepositoryProjectFile());
else
	aRevisionControl = new AdeRevisionControlNone;
AdeRevisionControlBase::SetRevisionControlObject(aRevisionControl);

UpdateItem(myRootItem);
