AstadeFile::UpdateUserAppIcons();
SetImageList(AstadeIcons::Instance());
wxTreeItemId myRootItem = AddRoot("model", 1);

wxConfigBase* theConfig = wxConfigBase::Get();
wxString modelPath = theConfig->Read("TreeView/ModelPath");

wxFileName modelDir;
modelDir.AssignDir(modelPath);
modelDir.MakeAbsolute();

AdeModel* aModel = new AdeModel(modelDir);

// Check wether the model is newer (modified by a newer version of Astade)
int saveVersion = aModel->GetSaveVersion();
if (saveVersion==0)
{
	aModel->SetSaveVersion(1);
}
else
{
	if (saveVersion > 2) // Model is not kompatibel to this Astade version
	{
		if (wxMessageBox("This model seems to be modified by a newer version of Astade. If you continue, things might not work propperly.\nBetter you get the newest version at http://Astade.tigris.org.\n\nDo You really want to try working with this Astade version (on your own risk)?",
				"Model has newer Version!", wxICON_QUESTION  | wxYES_NO) == wxNO)
		{
			DeleteAllItems();
			return;
		}
	}
}

SetItemData(myRootItem, AstadeTreeItemBase::CreateNewElement(aModel));

AdeGUIDCache::Instance()->Load(*aModel);

if (aModel->GetRepository() == "SVN")
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlSVN);
else if (aModel->GetRepository() == "git")
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlGIT);
else if (aModel->GetRepository() == "MKS")
{
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlMKS(aModel->GetRepositoryProjectFile()));
	if (saveVersion < 2)
	{
		aModel->SetSaveVersion(2);
	}
}
else
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlNone);

UpdateItem(myRootItem);