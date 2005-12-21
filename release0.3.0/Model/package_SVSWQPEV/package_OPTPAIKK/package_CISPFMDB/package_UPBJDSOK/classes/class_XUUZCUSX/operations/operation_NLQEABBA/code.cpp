wxFileName aName(myFileName);

aName.AppendDir("relations");

return wxFileName::DirExists(aName.GetPath());