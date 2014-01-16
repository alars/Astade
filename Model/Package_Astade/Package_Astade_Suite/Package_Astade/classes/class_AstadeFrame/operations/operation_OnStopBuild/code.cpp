//~~ void OnStopBuild(wxCommandEvent& event) [AstadeFrame] ~~
#ifdef __WXMSW__
// under Windows, Processes are created independent from their childs
// so if we want to kill them we have to do this seperately and bloody...
wxKill(runningMakePid, wxSIGKILL,NULL,wxKILL_CHILDREN);
#endif

wxProcess::Kill(runningMakePid, wxSIGTERM, wxKILL_CHILDREN);
