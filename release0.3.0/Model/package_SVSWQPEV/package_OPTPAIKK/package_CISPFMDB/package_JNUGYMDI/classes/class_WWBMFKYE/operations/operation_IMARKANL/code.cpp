if (GetIsInActiveComponent())
{
	if (GetImpGenerationTime() >= GetModificationTime())
		return 46;
	else
		return 47;
}
else
	return 5;