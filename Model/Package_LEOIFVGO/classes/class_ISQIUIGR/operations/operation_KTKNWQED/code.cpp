classWidth[classIndex] = width;

for (int i=0; i < GetClassCount(); ++i)
{
	int pos = GetLeftBorder();
	for (int j=0; j < i; ++j)
		pos += classWidth[j]+20;
	classCenter[i] = pos + classWidth[i]/2 + 10;
}