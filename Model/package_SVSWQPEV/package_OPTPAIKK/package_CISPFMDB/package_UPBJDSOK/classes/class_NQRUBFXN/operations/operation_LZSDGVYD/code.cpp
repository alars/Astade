wxString estimatedFilename = proposal;
estimatedFilename.Replace(" ","_");

wxString forbidden = wxFileName::GetForbiddenChars();

for (unsigned int i = 0; i < forbidden.size(); i++)
	estimatedFilename.Replace(wxString(forbidden.c_str()[i]),"_");

wxFileName realFileName = GetFileName();
wxFileName newFilename(realFileName);

newFilename.SetName(estimatedFilename);

int count = 0;

while ((newFilename != realFileName) && (newFilename.FileExists()))
{
	wxString suffix;
	suffix << ++count;
	newFilename.SetName(estimatedFilename + "_" + suffix);
}

return newFilename;