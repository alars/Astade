if (!options.isSet(AdeSearch::State))
	return AdeSearch::notfound;

return AdeFileElement::Search(options);