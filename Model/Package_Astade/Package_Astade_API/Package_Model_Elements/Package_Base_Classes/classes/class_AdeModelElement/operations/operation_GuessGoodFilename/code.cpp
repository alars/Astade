wxString estimatedFilename(proposal);
estimatedFilename.Replace(wxS(" "), wxS("_"));

wxString forbidden(wxFileName::GetForbiddenChars(wxPATH_UNIX));
forbidden += wxFileName::GetForbiddenChars(wxPATH_WIN);
forbidden += wxFileName::GetForbiddenChars(wxPATH_MAC);

for (unsigned int i = 0; i < forbidden.size(); i++)
	estimatedFilename.Replace(wxString(forbidden[i]), wxS("_"));

wxFileName realFileName(GetFileName());
wxFileName newFilename(realFileName);

newFilename.SetName(estimatedFilename);

int count = 0;

while (newFilename != realFileName && newFilename.FileExists())
{
	wxString suffix;
	suffix << ++count;
	newFilename.SetName(estimatedFilename + wxS("_") + suffix);
}

return newFilename;
