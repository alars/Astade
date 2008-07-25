if (IsLibClass())
	return myConfig->Read("Astade/ClassInclude");
else
	return wxEmptyString;
