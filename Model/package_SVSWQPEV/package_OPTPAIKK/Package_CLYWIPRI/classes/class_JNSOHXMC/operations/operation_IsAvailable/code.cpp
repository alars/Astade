wxPathList path;
path.AddEnvList("PATH");
return !path.FindValidPath("svn").IsEmpty();
