wxFileName parentPath = element.GetFileName();

int type = element.GetType();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName modelPath;
modelPath.AssignDir(theConfig->Read("TreeView/ModelPath"));
parentPath.MakeRelativeTo(modelPath.GetPath());

wxFileConfig aConfig(wxEmptyString, wxEmptyString, GetFileName().GetFullPath());
wxString mPath =  parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace("/","|");

if ((type & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)
	aConfig.Write(wxString("Statecharts/") + mPath, true);
else if ((type & ITEM_TYPE_MASK) == ITEM_IS_CLASS)
	aConfig.Write(wxString("Classes/") + mPath, true);
else
	return;

aConfig.Write("Astade/LastChanged", wxGetUTCTime());
aConfig.Flush();

/* Save Component-Path to the Class Modelnode.ini */
element.NotifyIsInComponent(*this);