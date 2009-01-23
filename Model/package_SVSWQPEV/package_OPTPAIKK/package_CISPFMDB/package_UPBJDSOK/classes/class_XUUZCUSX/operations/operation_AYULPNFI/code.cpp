AdeElementIterator iter = begin();
while(iter != end())
{
	wxTheApp->Yield(); // Its dangarous, but I've no better idea, yet
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
