wxFileName aName(myFileName);

aName.AppendDir("attributes");

return wxFileName::DirExists(aName.GetPath());