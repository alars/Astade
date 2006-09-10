wxFileName source = myFileName;
wxString sourceFileName = source.GetFullName();  //Get source file

wxFileName aFileName = parentPath;
aFileName.SetFullName(sourceFileName);  //Set destination file name same as source.

wxCopyFile(source.GetFullPath(), aFileName.GetFullPath());


return aFileName;
