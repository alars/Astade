//~~ void RemoveFromComponent(AdeModelElement& element) [AdeComponent] ~~

wxFileName parentPath = element.GetFileName();

parentPath.MakeRelativeTo(GetModelPath().GetPath());

wxString mPath = parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace(wxS("/"), wxS("|"));

myConfig->DeleteEntry(wxS("Statecharts/") + mPath);
myConfig->DeleteEntry(wxS("Classes/") + mPath);

myConfig->Flush();

/* Remove Component-Path from the Class Modelnode.ini */
element.NotifyIsNotInComponent(*this);
