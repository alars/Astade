//~~ void RemoveAstadeSpecials(wxArrayString& array) [OperationParser] ~~

for (unsigned int i = 0; i < array.GetCount(); )
{
	if (	(array[i].Left(3) == wxS("//["))
		||	(array[i].Find(wxS("NOTIFY_CONSTRUCTOR("))   != wxNOT_FOUND)
		||	(array[i].Find(wxS("NOTIFY_FUNCTION_CALL(")) != wxNOT_FOUND)
		||	(array[i].Find(wxS("NOTIFY_DESTRUCTOR("))    != wxNOT_FOUND)
		)
		array.RemoveAt(i, 1);
	else
		i++;
}
