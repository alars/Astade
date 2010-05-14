if (options.isSet(AdeSearch::Name) && options.RegEx().Matches(wxS(" ") + GetName() + wxS(" ")))
	return AdeSearch::found;

if (options.isSet(AdeSearch::Description) && options.RegEx().Matches(wxS(" ") + GetDescription() + wxS(" ")))
	return AdeSearch::found;

return AdeSearch::notfound;
