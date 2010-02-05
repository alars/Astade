if (!options.isSet(AdeSearch::Attribute))
	return AdeSearch::notfound;

if (options.isSet(AdeSearch::Name) && options.RegEx().Matches(" "+GetLabel()+" "))
	return AdeSearch::found;

if (options.isSet(AdeSearch::Description) && options.RegEx().Matches(" "+GetDescription()+" "))
	return AdeSearch::found;

return AdeSearch::notfound;