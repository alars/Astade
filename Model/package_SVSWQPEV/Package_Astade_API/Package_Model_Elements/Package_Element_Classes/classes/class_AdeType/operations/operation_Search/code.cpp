if (!options.isSet(AdeSearch::Type))
	return AdeSearch::notfound;

if (options.isSet(AdeSearch::theType) && options.RegEx().Matches(" "+GetDeclaration()+" "))
	return AdeSearch::found;

return AdeFileElement::Search(options);