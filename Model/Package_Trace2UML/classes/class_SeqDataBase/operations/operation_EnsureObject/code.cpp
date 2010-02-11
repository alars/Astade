if (object.empty() || object == _T("*") || object == _T("~") || object == _T("???"))
	return wxNOT_FOUND;

int index = classes.Index(object);

if (index == wxNOT_FOUND && classes.GetCount() < MAXCLASSCOUNT)
{
	index = AddObject(object);
	AddEventExist(index);
}

return index;
