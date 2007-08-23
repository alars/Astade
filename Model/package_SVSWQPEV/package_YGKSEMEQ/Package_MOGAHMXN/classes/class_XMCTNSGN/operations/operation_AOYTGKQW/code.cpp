if (static_cast<AdeClass*>(myModelElement)->GetIsLibClass())
	return 57;

if (static_cast<AdeClass*>(myModelElement)->GetIsInActiveComponent())
{
	if (static_cast<AdeClass*>(myModelElement)->GetImpGenerationTime() >= static_cast<AdeClass*>(myModelElement)->GetModificationTime())
		return 46;
	else
		return 47;
}
else
	return 5;