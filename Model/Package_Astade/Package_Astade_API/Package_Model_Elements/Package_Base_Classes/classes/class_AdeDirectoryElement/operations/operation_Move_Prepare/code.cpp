// prepare all the childs
for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	wxArrayString dirs = myFileName.GetDirs();	
	wxFileName toPath(parentPath);
	toPath.AppendDir(dirs.Last());
	anElement->Move_Prepare(toPath);
	delete anElement;
}

AdeModelElement::Move_Prepare(parentPath);
