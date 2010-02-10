for (AdeElementIterator iter = begin(); iter != end(); ++iter)
{
	wxTheApp->Yield(true); // It's dangerous, but I haven't got any better idea, yet
	AdeModelElement* anElement = iter.CreateNewElement();
	if (anElement->Search(options) != AdeSearch::notfound)
	{
		delete anElement;
		return AdeSearch::contain;
	}

	delete anElement;
}

return AdeSearch::notfound;
