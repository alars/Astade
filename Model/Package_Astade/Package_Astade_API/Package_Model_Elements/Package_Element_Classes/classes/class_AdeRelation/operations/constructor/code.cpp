// If the partner InRelation does not exist it gets created
if (!GetPartnerFile().FileExists())
{
	if (!wxFileName::DirExists(GetPartnerFile().GetPath()))
	{
		wxFileName relationsDir;
		relationsDir.AssignDir(GetPartnerFile().GetPath());
		int i = relationsDir.GetDirCount();
		relationsDir.RemoveDir(i-1);
		if (wxFileName::DirExists(relationsDir.GetPath()))
			AdeRelations::CreateNewElement(relationsDir);
		else
			return;
	}

	wxFileConfig theConfig(wxEmptyString, wxEmptyString, GetPartnerFile().GetFullPath());

	wxFileName thisFileName = myFileName;
	thisFileName.MakeRelativeTo(GetModelPath().GetPath());

	theConfig.Write(wxS("Astade/Name"), wxS("inrelation"));
	theConfig.Write(wxS("Astade/Type"), ITEM_IS_INRELATION);
	theConfig.Write(wxS("Astade/PartnerPath"), thisFileName.GetFullPath(wxPATH_UNIX));
	theConfig.Flush();

	AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
	if (theRevisionControl->IsAddSupported())
		theRevisionControl->Add(GetPartnerFile());
}
