//~~ void RemoveFirst(wxArrayString& array) [OperationParser] ~~

for (unsigned int i = 0; i < array.GetCount(); ++i)
	if (!array[i].empty())
		array[i].Remove(0,1);
