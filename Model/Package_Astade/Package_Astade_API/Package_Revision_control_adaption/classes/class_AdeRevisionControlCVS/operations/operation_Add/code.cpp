//~~ int Add(const wxFileName& fileName) [AdeRevisionControlCVS] ~~
theOutput.Clear();

wxFileName parent(fileName);
parent.MakeAbsolute();

wxString cmd;
if (parent.IsDir())
{
    wxString lastDir = parent.GetDirs()[parent.GetDirCount()-1];
    parent.RemoveLastDir();
    cmd = wxS("cd \"") + parent.GetPath() + wxS("\" && cvs add \"") + lastDir + wxS("\"");
}
else
{
    cmd = wxS("cd \"") + parent.GetPath() + wxS("\" && cvs add \"") + parent.GetFullName() + wxS("\"");
}

theOutput.Add(cmd);

return wxShell(cmd);
