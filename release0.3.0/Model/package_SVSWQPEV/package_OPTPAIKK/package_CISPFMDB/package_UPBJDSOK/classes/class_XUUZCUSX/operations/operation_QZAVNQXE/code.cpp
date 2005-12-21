wxFileName aName(myFileName);

aName.AppendDir("parameters");

return wxFileName::DirExists(aName.GetPath());