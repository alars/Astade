if ((object.empty()) || (object=="*") || (object=="~"))
	return wxNOT_FOUND;

int index = classes.Index(object);

if ((index==wxNOT_FOUND) && (classes.GetCount()<MAXCLASSCOUNT))
{
	index = AddObject(object);
	AddEventExist(index);
}

return index;