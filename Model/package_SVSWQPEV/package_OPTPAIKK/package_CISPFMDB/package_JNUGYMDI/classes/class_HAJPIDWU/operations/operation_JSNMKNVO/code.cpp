wxString estimatedFilename = GetName();
estimatedFilename.Replace(" ","_");
estimatedFilename = "attribute_" + estimatedFilename;

wxFileName realFileName = GetFileName();
wxFileName newFilename(realFileName);

newFilename.SetName(estimatedFilename);

if ((realFileName != newFilename) && (!newFilename.FileExists()))
	AdeRevisionControlBase::GetRevisionControlObject()->Move(realFileName,newFilename);