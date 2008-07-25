if (indexBase == -1) // not yet initialized
	InitializeIcons();


if (static_cast<AdeStatechart*>(myModelElement)->IsLibClass())
	return indexBase + 3;

if (static_cast<AdeStatechart*>(myModelElement)->IsInActiveComponent())
{
	if (static_cast<AdeStatechart*>(myModelElement)->GetImpGenerationTime() >= static_cast<AdeStatechart*>(myModelElement)->GetModificationTime())
		return indexBase + 1;
	else
		return indexBase + 2;
}
else
	return indexBase + 0;
