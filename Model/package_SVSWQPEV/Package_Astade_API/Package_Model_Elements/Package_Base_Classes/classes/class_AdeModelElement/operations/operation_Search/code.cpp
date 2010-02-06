if (options.isSet(AdeSearch::Name) && options.RegEx().Matches(" "+GetName()+" "))
	return AdeSearch::found;

if (options.isSet(AdeSearch::Description) && options.RegEx().Matches(" "+GetDescription()+" "))
	return AdeSearch::found;

return AdeSearch::notfound;