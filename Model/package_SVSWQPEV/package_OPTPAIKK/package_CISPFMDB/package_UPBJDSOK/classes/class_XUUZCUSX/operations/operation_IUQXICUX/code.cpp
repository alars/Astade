AdeElementIterator it;

for (it=begin();it!=end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	aElement->Delete();
	delete aElement;
}

wxRemoveFile(myFileName.GetFullPath());
wxRmdir(myFileName.GetPath());
