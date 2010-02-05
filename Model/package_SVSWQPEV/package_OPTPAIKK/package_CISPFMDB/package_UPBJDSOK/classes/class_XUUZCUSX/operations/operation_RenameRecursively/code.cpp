// prepare all the childs
for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	anElement->RenameRecursively();
	delete anElement;
}
Rename();
