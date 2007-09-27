wxASSERT_MSG(aProperty.GetName().IsEmpty(), "You tried to add a new property with no name.")

if(aProperty.GetName().IsEmpty())
	return;

AdePropertyMap::iterator curr = myPropertyMap.find(aProperty.GetName());

if(curr != myPropertyMap.end())
{
	if(curr->second)
		delete(curr->second);
}

myPropertyMap[aProperty.GetName()] = new AdeProperty(aProperty) ;
