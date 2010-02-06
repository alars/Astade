int count = GetLeftBorder() + GetRightBorder();

for (int i = 0; i < GetClassCount(); i++)
	count += GetClassWidth(i);

return count;
