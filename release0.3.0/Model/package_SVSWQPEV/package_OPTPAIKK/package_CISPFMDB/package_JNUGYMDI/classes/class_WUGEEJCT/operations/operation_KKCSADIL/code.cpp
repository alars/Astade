wxFileName classFileName = myFileName;

int i = classFileName.GetDirCount();
classFileName.RemoveDir(i);
classFileName.RemoveDir(i-1);
classFileName.RemoveDir(i-2);
classFileName.SetFullName("ModelNode.ini");


wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,classFileName.GetFullPath());

return "~" + theConfig.Read("Astade/Name","<name unknown>");
