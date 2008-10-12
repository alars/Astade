AstadeFile::UpdateUserAppIcons();
SetImageList(AstadeIcons::Instance());
wxTreeItemId myRootItem = AddRoot("model", 1);

wxConfigBase* theConfig = wxConfigBase::Get();
wxString modelPath = theConfig->Read("TreeView/ModelPath");

wxFileName modelDir;
modelDir.AssignDir(modelPath);
modelDir.MakeAbsolute();
wxFileName::SetCwd(modelDir.GetPath());

AdeModel* aModel = new AdeModel(modelDir);

// Check whether the model is newer (modified by a newer version of Astade)
int saveVersion = aModel->GetSaveVersion();

if (saveVersion > 3) // Model is not compatible with this Astade version
{
    if (wxMessageBox("This model seems to have been modified by a newer version of Astade. If you continue, things might not work propperly.\nYou had better get the newest version at http://Astade.tigris.org.\n\nDo you really want to try working with this Astade version (on your own risk)?",
            "Model has newer Version!", wxICON_QUESTION  | wxYES_NO) == wxNO)
    {
        DeleteAllItems();
        return;
    }
}

if (saveVersion < 3) // if we continue here, we have at least save version 3 
{
    aModel->SetSaveVersion(3);
}

SetItemData(myRootItem, AstadeTreeItemBase::CreateNewElement(aModel));

AdeGUIDCache::Instance()->Load(*aModel);

AdeRevisionControlBase* aRevisionControl;
if (aModel->GetRepository() == "SVN")
{
	bool git_svn;
	theConfig->Read("Repository/git-svn", &git_svn, false);
	if (git_svn)
		aRevisionControl = new AdeRevisionControlGIT;
	else
		aRevisionControl = new AdeRevisionControlSVN;
}
else if (aModel->GetRepository() == "git")
	aRevisionControl = new AdeRevisionControlGIT;
else if (aModel->GetRepository() == "MKS")
	aRevisionControl = new AdeRevisionControlMKS(aModel->GetRepositoryProjectFile());
else
	aRevisionControl = new AdeRevisionControlNone;
AdeRevisionControlBase::SetRevisionControlObject(aRevisionControl);

UpdateItem(myRootItem);
