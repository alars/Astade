//~~ AdeSearch::returnValues Search(const AdeSearch& options) [AdePorts] ~~
if (!options.isSet(AdeSearch::Attribute))
	return AdeSearch::notfound;

return AdeDirectoryElement::Search(options);