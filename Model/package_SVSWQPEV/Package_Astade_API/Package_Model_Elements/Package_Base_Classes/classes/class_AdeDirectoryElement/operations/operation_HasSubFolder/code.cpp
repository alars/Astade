wxFileName aName(myFileName);
aName.AppendDir(folderName);
return wxFileName::DirExists(aName.GetPath());