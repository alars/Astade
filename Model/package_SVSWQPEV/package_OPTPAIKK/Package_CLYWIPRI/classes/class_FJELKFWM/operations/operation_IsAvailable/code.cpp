wxPathList path;
path.AddEnvList("PATH");
return !path.FindValidPath("pj").IsEmpty();
