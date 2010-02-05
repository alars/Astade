wxString path = parentPath.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
wxString name = myFileName.GetFullName();
wxArrayString dirs = myFileName.GetDirs();	

myFileName.Assign(path, name);
myFileName.AppendDir(dirs.Last());

// complete all the childs
for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	anElement->Move_Complete(myFileName.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR));
	delete anElement;
}
