//~~ int AddObject(const wxString& object) [SeqDataBase] ~~

if (object.empty() || object == wxS("*"))
	return wxNOT_FOUND;

int index = classes.Index(object);

if (index == wxNOT_FOUND && classes.GetCount() < MAXCLASSCOUNT)
{
	classes.Add(object);
	if (object.size() > longestObjectName)
		longestObjectName = object.size();
	index = classes.Index(object);
	if (myEditMenu)
        myEditMenu->Append(ID_EDITBEGIN + index, wxS("delete: ") + object, wxEmptyString, wxITEM_NORMAL);
}

return index;
