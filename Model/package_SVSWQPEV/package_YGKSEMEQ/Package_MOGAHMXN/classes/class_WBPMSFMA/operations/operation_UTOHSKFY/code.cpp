if (myModelElement->GetFileName().GetExt()=="cpp")
	return 37;
if (myModelElement->GetFileName().GetExt()=="h")
	return 39;
if (myModelElement->GetFileName().GetExt()=="dox")
	return 66;

return 0;