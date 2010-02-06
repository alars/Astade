if (object.empty() || object == _T("*"))
	return wxNOT_FOUND;

int index = classes.Index(object);

if (index == wxNOT_FOUND && classes.GetCount() < MAXCLASSCOUNT)
{
	classes.Add(object);
	if (object.size() > longestObjectName)
		longestObjectName = object.size();
	index = classes.Index(object);
	if (myEditMenu)
        myEditMenu->Append(ID_EDITBEGIN + index, _T("delete: ") + object, _T(""), wxITEM_NORMAL);
}

return index;
