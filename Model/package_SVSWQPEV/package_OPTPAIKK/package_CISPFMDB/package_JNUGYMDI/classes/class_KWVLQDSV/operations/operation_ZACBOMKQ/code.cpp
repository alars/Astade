wxFileName parentPath = element.GetFileName();

parentPath.MakeRelativeTo(GetModelPath().GetPath());

wxFileConfig aConfig(wxEmptyString, wxEmptyString, GetFileName().GetFullPath());
wxString mPath =  parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace("/","|");

aConfig.DeleteEntry(wxString("Statecharts/") + mPath);
aConfig.DeleteEntry(wxString("Classes/") + mPath);

aConfig.Write("Astade/LastChanged", wxGetUTCTime());
aConfig.Flush();

/* Remove Component-Path from the Class Modelnode.ini */
element.NotifyIsNotInComponent(*this);
