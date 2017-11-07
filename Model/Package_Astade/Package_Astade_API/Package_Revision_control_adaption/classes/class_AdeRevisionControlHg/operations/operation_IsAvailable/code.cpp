//~~ bool IsAvailable() [AdeRevisionControlHg] ~~
#ifdef __WXMSW__
#  define EXE_EXT ".exe"
#else
#  define EXE_EXT
#endif
wxPathList path;
path.AddEnvList(wxS("PATH"));
return !path.FindValidPath(wxS("hg" EXE_EXT)).IsEmpty();
