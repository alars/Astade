if (GetIsInActiveComponent())
{
	if (GetImpGenerationTime() >= GetModificationTime())
		return 50;
	else
		return 51;
}
else
	return 49;