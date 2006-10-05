wxString path = parentPath.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
wxString name = myFileName.GetFullName();
wxArrayString dirs = myFileName.GetDirs();	

myFileName.Assign(path, name);
myFileName.AppendDir(dirs.Last());

AdeElementIterator it;

// complete all the childs
for (it=begin();it!=end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	aElement->Move_Complete(myFileName.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR));
	delete(aElement);
}