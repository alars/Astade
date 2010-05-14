if (IsLibClass())
	return myConfig->Read(wxS("Astade/ClassInclude"));
else
	return wxEmptyString;
