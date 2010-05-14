wxFileName parentPath = element.GetFileName();

parentPath.MakeRelativeTo(GetModelPath().GetPath());

wxFileConfig aConfig(wxEmptyString, wxEmptyString, GetFileName().GetFullPath());
wxString mPath =  parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace(wxS("/"), wxS("|"));

aConfig.DeleteEntry(wxS("Statecharts/") + mPath);
aConfig.DeleteEntry(wxS("Classes/") + mPath);

aConfig.Flush();

/* Remove Component-Path from the Class Modelnode.ini */
element.NotifyIsNotInComponent(*this);
