if (indexBase == -1) // not yet initialized
	InitializeIcons();

std::map<wxString, int>::iterator iter =
	myUserAppIcons.find((myModelElement->GetFileName()).GetExt());

if(iter != myUserAppIcons.end())
	return	iter->second;
else
	return indexBase;