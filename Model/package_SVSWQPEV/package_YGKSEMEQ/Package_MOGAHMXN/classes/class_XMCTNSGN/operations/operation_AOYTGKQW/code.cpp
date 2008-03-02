if (indexBase == -1) // not yet initialized
	InitializeIcons();

int ret = indexBase;

if (static_cast<AdeClass*>(myModelElement)->GetIsLibClass())
	ret += 3;

if (static_cast<AdeClass*>(myModelElement)->GetIsInActiveComponent())
{
	if (static_cast<AdeClass*>(myModelElement)->GetImpGenerationTime() >= static_cast<AdeClass*>(myModelElement)->GetModificationTime())
		ret += 1;
	else
		ret += 2;
}

if (static_cast<AdeClass*>(myModelElement)->GetIsCCoded())
	ret += 4;

return ret;