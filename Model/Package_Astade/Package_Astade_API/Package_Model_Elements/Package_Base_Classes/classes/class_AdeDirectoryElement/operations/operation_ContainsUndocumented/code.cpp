//~~ bool ContainsUndocumented() [AdeDirectoryElement] ~~

bool retVal = false;

AdeElementIterator iter = begin();
while(!retVal && iter != end())
{
	AdeModelElement* anElement = iter.CreateNewElement();
	AdeDirectoryElement* aDirElement = dynamic_cast<AdeDirectoryElement*>(anElement);

	retVal |= anElement->IsUndocumented(); // check if subelement is undocumented itself
	retVal |= aDirElement && aDirElement->ContainsUndocumented(); // or if the subelement contains undocumented ones

	delete anElement;
	++iter;
}

return retVal;
