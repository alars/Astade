if (!options.isSet(AdeSearch::Parameter))
	return AdeSearch::notfound;

if (options.isSet(AdeSearch::theType) && options.RegEx().Matches(" "+GetCodingType()+" "))
	return AdeSearch::found;

if (options.isSet(AdeSearch::Default) && options.RegEx().Matches(" "+GetDefault()+" "))
	return AdeSearch::found;

return AdeFileElement::Search(options);