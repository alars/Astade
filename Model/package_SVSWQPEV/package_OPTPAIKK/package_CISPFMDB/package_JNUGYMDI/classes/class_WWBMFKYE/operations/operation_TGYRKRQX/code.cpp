if (GetIsLibClass())
	return myConfig->Read("Astade/ClassInclude");
else
	return wxEmptyString;