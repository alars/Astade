if (!options.isSet(AdeSearch::State))
	return AdeSearch::notfound;

AdeSearch::returnValues ret = AdeModelElement::Search(options);
if (ret != AdeSearch::notfound)
	return ret;

return AdeDirectoryElement::Search(options);