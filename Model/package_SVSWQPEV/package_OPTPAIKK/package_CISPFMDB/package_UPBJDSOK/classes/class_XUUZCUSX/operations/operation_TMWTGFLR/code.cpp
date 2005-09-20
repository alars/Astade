wxFileName aName(myFileName);

aName.AppendDir("classes");

return wxFileName::DirExists(aName.GetPath());