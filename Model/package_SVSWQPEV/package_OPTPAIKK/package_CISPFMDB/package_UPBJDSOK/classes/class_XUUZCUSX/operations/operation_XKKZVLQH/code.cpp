AdeElementIterator it;

// prepare all the childs
for (it=begin();it!=end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	wxArrayString dirs = myFileName.GetDirs();	
	wxFileName toPath(parentPath);
	toPath.AppendDir(dirs.Last());
	aElement->Move_Prepare(toPath);
	delete(aElement);
}

AdeModelElement::Move_Prepare(parentPath);