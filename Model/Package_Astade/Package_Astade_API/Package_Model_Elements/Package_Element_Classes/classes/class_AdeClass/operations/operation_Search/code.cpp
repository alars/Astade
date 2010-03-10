if (options.isSet(AdeSearch::activeComponentOnly) && (!IsInActiveComponent()))
	return AdeSearch::notfound;
	
if (options.isSet(AdeSearch::Class))
{
	AdeSearch::returnValues ret = AdeModelElement::Search(options);
	if (ret != AdeSearch::notfound)
		return ret;
}

return AdeDirectoryElement::Search(options);
