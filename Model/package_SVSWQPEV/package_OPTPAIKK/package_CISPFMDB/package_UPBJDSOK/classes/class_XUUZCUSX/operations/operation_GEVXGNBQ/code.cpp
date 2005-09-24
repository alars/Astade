wxFileName aName(myFileName);

aName.AppendDir("operations");

return wxFileName::DirExists(aName.GetPath());