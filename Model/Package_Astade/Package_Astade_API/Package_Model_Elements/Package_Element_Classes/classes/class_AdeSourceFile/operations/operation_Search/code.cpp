//~~ AdeSearch::returnValues Search(const AdeSearch& options) [AdeSourceFile] ~~

if (!options.isSet(AdeSearch::UserCode))
	return AdeSearch::notfound;

if (!options.isSet(AdeSearch::theUserCode))
	return AdeSearch::notfound;

char Buffer[100000];

Buffer[0] = ' ';
FILE* aFile = fopen(GetFileName().GetFullPath().utf8_str(), "r");

if (aFile == NULL)
	return AdeSearch::notfound;

int count = fread(&Buffer[1], 1, sizeof(Buffer) - 3, aFile);
fclose(aFile);
if (count < 0)
	return AdeSearch::notfound;

Buffer[count+1] = ' ';
Buffer[count+2] = 0;

if (options.RegEx().Matches(wxString::FromUTF8(Buffer)))
	return AdeSearch::found;

return AdeSearch::notfound;
