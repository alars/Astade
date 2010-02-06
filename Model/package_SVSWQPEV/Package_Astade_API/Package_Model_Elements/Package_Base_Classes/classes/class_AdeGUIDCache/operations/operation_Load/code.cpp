myCacheMemory.clear();

for (AdeElementIterator it = model.begin(); it != model.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	AdeDirectoryElement* aDirElement = dynamic_cast<AdeDirectoryElement*>(anElement);

	if (aDirElement)
		Include(*aDirElement);

	delete anElement;
}