wxString estimatedFilename = GetName();
estimatedFilename.Replace(" ","_");
estimatedFilename = "Config_" + estimatedFilename;

wxFileName realFileName = GetFileName();
wxFileName newFilename(realFileName);

newFilename.RemoveLastDir();
newFilename.AppendDir(estimatedFilename);

realFileName.SetFullName(wxEmptyString);
newFilename.SetFullName(wxEmptyString);

if (realFileName != newFilename)
	AdeRevisionControlBase::GetRevisionControlObject()->Move(realFileName,newFilename);