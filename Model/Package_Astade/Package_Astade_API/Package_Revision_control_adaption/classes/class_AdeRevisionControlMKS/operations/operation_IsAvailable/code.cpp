#ifdef __WXMSW__
#  define EXE_EXT ".exe"
#else
#  define EXE_EXT
#endif
wxPathList path;
path.AddEnvList("PATH");
return !path.FindValidPath("pj" EXE_EXT).IsEmpty();
