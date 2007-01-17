wxString estimatedFilename = GetName();
estimatedFilename.Replace(" ","_");
estimatedFilename = "Components_" + estimatedFilename;

wxFileName realFileName = GetFileName();
wxFileName newFilename(realFileName);

newFilename.RemoveLastDir();
newFilename.AppendDir(estimatedFilename);

wxLogMessage("old fileneame = %s",realFileName.GetFullPath().c_str());
wxLogMessage("new fileneame = %s",newFilename.GetFullPath().c_str());