if (indexBase == -1) // not yet initialized
	InitializeIcons();


if (static_cast<AdeClass*>(myModelElement)->GetIsLibClass())
	return 57;

if (static_cast<AdeClass*>(myModelElement)->GetIsInActiveComponent())
{
	if (static_cast<AdeClass*>(myModelElement)->GetImpGenerationTime() >= static_cast<AdeClass*>(myModelElement)->GetModificationTime())
		return indexBase + 1;
	else
		return indexBase + 2;
}
else
	return indexBase + 0;