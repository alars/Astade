if (static_cast<AdeStatechart*>(myModelElement)->GetIsInActiveComponent())
{
	if (static_cast<AdeStatechart*>(myModelElement)->GetImpGenerationTime() >= static_cast<AdeStatechart*>(myModelElement)->GetModificationTime())
		return 50;
	else
		return 51;
}
else
	return 49;