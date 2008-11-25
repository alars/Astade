bool retVal = false;

AdeElementIterator iter = begin();
while(!retVal && (iter != end()))
{
	AdeModelElement* aElement = iter.CreateNewElement();
	AdeDirectoryElement* aDirElement = dynamic_cast<AdeDirectoryElement*>(aElement);

	retVal |= aElement->IsUndocumented(); // check if subelement is undocumented itself
	retVal |= (aDirElement && aDirElement->ContainsUndocumented()); // or if the subelement contains undocumented ones
	
	delete aElement;
	++iter;	
}

return retVal;
