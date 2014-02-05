//~~ bool RepoExists() [AdeRevisionControlSVN] ~~

wxArrayString theOutput;
return wxExecute(wxS("svn info"), theOutput) == 0;
