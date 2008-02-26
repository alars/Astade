if (indexBase == -1) // not yet initialized
	InitializeIcons();

if (myModelElement->GetFileName().GetExt()=="cpp")
	return indexBase;
if (myModelElement->GetFileName().GetExt()=="h")
	return indexBase + 1;
if (myModelElement->GetFileName().GetExt()=="dox")
	return indexBase + 2;
if (myModelElement->GetFileName().GetExt()=="c")
	return indexBase + 3;

return 0;