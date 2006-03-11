if (myFileName.GetExt()=="cpp")
	return 37;
if (myFileName.GetExt()=="h")
	return 39;
if (myFileName.GetExt()=="dox")
	return 66;

return AdeModelElement::GetIconIndex();