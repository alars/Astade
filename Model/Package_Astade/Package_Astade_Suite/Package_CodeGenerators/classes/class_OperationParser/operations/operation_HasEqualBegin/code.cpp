//~~ bool HasEqualBegin(const wxArrayString& array, char c) [OperationParser] ~~

if (array.GetCount() == 0)
	return false;

for (unsigned int i = 0; i < array.GetCount(); i++)
	if (!array[i].empty() && array[i][0] != c)
		return false;

return true;
