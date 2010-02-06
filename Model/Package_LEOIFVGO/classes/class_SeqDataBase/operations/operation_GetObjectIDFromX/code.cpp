int index = 0;
int distance = 999999;
for (int i = 0; i < GetClassCount(); ++i)
{
	int thisDistance = abs(GetClassMiddle(i)-x);
	if (thisDistance < distance)
	{
		distance = thisDistance;
		index = i;
	}
}

return index;