//~~ int GetIconIndex() [AstadeSourceFile] ~~

wxArrayString names;

names.Add("file");

wxFileName aName = myModelElement->GetFileName();

if (aName.GetExt() == "cpp")
	names.Add(CODE_CPlusPlus);
else if (aName.GetExt() == "h")
	names.Add("h");
else if (aName.GetExt() == "dox")
	names.Add("doxygen");
else if (aName.GetExt() == "c")
	names.Add(CODE_C);

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
	case AdeSearch::contain:
		names.Add("hasfound");
		break;
	case AdeSearch::found:
		names.Add("found");
		break;
	default:
		break;
	}
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
