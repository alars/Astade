wxFileName aName(myFileName);

aName.AppendDir("types");

return wxFileName::DirExists(aName.GetPath());