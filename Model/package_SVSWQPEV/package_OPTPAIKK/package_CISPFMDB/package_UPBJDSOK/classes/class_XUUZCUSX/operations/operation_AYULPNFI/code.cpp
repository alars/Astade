AdeElementIterator iter = begin();
while(iter != end())
{
	AdeModelElement* aElement = iter.CreateNewElement();
	if (aElement->Search(options) != AdeSearch::notfound)
	{
		delete aElement;
		return AdeSearch::contain;
	}

	delete aElement;
	++iter;
}

return AdeSearch::notfound;