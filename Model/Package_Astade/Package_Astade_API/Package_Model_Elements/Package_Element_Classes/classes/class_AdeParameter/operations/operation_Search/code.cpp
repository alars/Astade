if (!options.isSet(AdeSearch::Parameter))
	return AdeSearch::notfound;

if (options.isSet(AdeSearch::theType) && options.RegEx().Matches(wxS(" ") + GetCodingType() + wxS(" ")))
	return AdeSearch::found;

if (options.isSet(AdeSearch::Default) && options.RegEx().Matches(wxS(" ") + GetDefault() + wxS(" ")))
	return AdeSearch::found;

return AdeFileElement::Search(options);
