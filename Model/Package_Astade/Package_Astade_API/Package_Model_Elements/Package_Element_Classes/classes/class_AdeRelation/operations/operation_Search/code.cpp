if (!options.isSet(AdeSearch::Attribute))
	return AdeSearch::notfound;

if (options.isSet(AdeSearch::Name) && options.RegEx().Matches(wxS(" ") + GetLabel() + wxS(" ")))
	return AdeSearch::found;

if (options.isSet(AdeSearch::Description) && options.RegEx().Matches(wxS(" ") + GetDescription() + wxS(" ")))
	return AdeSearch::found;

return AdeSearch::notfound;
