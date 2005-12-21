if (!GetPartnerFile().FileExists())
{
	if (!wxFileName::DirExists(GetPartnerFile().GetPath()))
	{
		wxFileName relationsDir;
		relationsDir.AssignDir(GetPartnerFile().GetPath());
		int i = relationsDir.GetDirCount();
		relationsDir.RemoveDir(i);
		relationsDir.RemoveDir(i-1);
		AdeDirectoryElement::CreateNewElement(relationsDir,"relations",ITEM_IS_RELATIONS,false);
	}

	wxFileConfig theConfig(wxEmptyString,wxEmptyString,GetPartnerFile().GetFullPath());

	wxConfigBase* aConfig = wxConfigBase::Get();
	wxString modelPath = aConfig->Read("TreeView/ModelPath");
	wxFileName thisFileName = myFileName;
	thisFileName.MakeRelativeTo(modelPath);

	theConfig.Write("Astade/Name","inrelation");
	theConfig.Write("Astade/Type",ITEM_IS_INRELATION);
	theConfig.Write("Astade/ID",IDSTRING);
	theConfig.Write("Astade/LastChanged",wxGetUTCTime());
	theConfig.Write("Astade/PartnerPath", thisFileName.GetFullPath(wxPATH_UNIX));
}