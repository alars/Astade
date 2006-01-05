if ((object.empty()) || (object=="*"))
	return wxNOT_FOUND;

int index = classes.Index(object);

if ((index==wxNOT_FOUND) && (classes.GetCount()<MAXCLASSCOUNT))
{
	classes.Add(object);
	if (object.size()>longestObjectName)
		longestObjectName = object.size();
	index = classes.Index(object);
}

return index;