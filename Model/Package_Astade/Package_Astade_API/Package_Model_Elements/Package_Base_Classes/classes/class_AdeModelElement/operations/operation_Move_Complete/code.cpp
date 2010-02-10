// set the Filename of this Object to the new Location
wxString path = parentPath.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
wxString file = myFileName.GetFullName();
myFileName.Assign(path, file);