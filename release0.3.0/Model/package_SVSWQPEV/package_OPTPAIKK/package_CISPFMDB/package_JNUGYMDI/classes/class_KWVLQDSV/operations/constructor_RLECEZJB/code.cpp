if (!GetHasChildren())
{
	AdeDirectoryElement::CreateNewElement(myFileName,"auto",ITEM_IS_FILES,false);
	AdeDirectoryElement::CreateNewElement(myFileName,"manual",ITEM_IS_FILES,false);
}