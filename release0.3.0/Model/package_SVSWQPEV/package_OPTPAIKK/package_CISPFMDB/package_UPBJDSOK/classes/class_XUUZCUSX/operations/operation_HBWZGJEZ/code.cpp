wxFileName aName(myFileName);

aName.AppendDir("destructor");

return wxFileName::DirExists(aName.GetPath());