//~~ int EnsureObject(const wxString& object) [SeqDataBase] ~~
if (object.empty() || object == wxS("*") || object == wxS("~") || object == wxS("???"))
	return wxNOT_FOUND;

int index = classes.Index(object);

if (index == wxNOT_FOUND && classes.GetCount() < MAXCLASSCOUNT)
{
	index = AddObject(object);
	AddEventExist(index);
}

return index;
