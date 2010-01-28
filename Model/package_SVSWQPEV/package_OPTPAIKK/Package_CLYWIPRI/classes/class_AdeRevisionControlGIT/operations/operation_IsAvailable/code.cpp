wxPathList path;
path.AddEnvList("PATH");
return !path.FindValidPath("git").IsEmpty();
