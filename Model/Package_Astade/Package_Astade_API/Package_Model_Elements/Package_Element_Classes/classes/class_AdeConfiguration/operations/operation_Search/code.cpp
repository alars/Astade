if (options.isSet(AdeSearch::Component))
{
	AdeSearch::returnValues ret = AdeModelElement::Search(options);
	if (ret != AdeSearch::notfound)
		return ret;
}

return AdeDirectoryElement::Search(options);