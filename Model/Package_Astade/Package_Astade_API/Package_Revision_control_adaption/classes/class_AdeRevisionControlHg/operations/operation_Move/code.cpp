//~~ int Move(const wxFileName& fromFileName, const wxFileName& toFileName) [AdeRevisionControlHg] ~~

theOutput.Clear();
wxFileName from(fromFileName);
wxFileName to  (toFileName);
from.MakeRelativeTo();
to  .MakeRelativeTo();
wxString cmd = wxS("hg mv \"") + from.GetFullPath(wxPATH_UNIX) + wxS("\" \"") + to.GetFullPath(wxPATH_UNIX) + wxS("\"");
theOutput.Add(cmd);
return wxExecute(cmd, theOutput);
