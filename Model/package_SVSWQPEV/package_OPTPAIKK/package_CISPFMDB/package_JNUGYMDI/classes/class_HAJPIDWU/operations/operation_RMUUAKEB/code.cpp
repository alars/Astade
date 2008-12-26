if (!options.isSet(AdeSearch::Attribute))
	return AdeSearch::notfound;

if (options.isSet(AdeSearch::Name) && options.RegEx().Matches(GetName()))
	return AdeSearch::found;

if (options.isSet(AdeSearch::Default) && options.RegEx().Matches(GetDefault()))
	return AdeSearch::found;

if (options.isSet(AdeSearch::Description) && options.RegEx().Matches(GetDescription()))
	return AdeSearch::found;

if (options.isSet(AdeSearch::theType) && options.RegEx().Matches(GetCodingType()))
	return AdeSearch::found;

return AdeSearch::notfound;