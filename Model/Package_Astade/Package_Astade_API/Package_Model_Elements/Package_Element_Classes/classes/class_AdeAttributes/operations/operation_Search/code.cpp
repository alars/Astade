//~~ AdeSearch::returnValues Search(const AdeSearch& options) [AdeAttributes] ~~
if (!options.isSet(AdeSearch::Attribute))
	return AdeSearch::notfound;

return AdeDirectoryElement::Search(options);