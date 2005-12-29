if (object=="*")
	return wxNOT_FOUND;

if ((classes.Index(object)==wxNOT_FOUND) && (classes.GetCount()<32))
{
	classes.Add(object);
	if (object.size()>longestObjectName)
		longestObjectName = object.size();
}

return classes.Index(object);