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
{
	wxLogMessage("old fileneame = %s",realFileName.GetFullPath().c_str());
	wxLogMessage("new fileneame = %s",newFilename.GetFullPath().c_str());

	AdeRevisionControlBase::GetRevisionControlObject()->Move(realFileName,newFilename);
}