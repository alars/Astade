theOutput.Clear();
wxFileName from(fromFileName);
wxFileName to  (toFileName);
from.MakeRelativeTo();
to  .MakeRelativeTo();
wxString cmd = "git-mv \"" + from.GetFullPath(wxPATH_UNIX) + "\" \"" + to.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
return wxExecute(cmd, theOutput);
