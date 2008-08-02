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
    if (wxMessageBox("This model seems to be modified by a newer version of Astade. If you continue, things might not work propperly.\nBetter you get the newest version at http://Astade.tigris.org.\n\nDo You really want to try working with this Astade version (on your own risk)?",
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

if (aModel->GetRepository() == "SVN")
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlSVN);
else if (aModel->GetRepository() == "git")
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlGIT);
else if (aModel->GetRepository() == "MKS")
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlMKS(aModel->GetRepositoryProjectFile()));
else
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlNone);

UpdateItem(myRootItem);
