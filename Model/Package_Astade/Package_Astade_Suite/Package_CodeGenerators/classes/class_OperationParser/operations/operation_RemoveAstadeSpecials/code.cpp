unsigned int i = 0;

while (i<array.GetCount())
{
	if (	(array[i].Left(3) == "//[")
		||	(array[i].Find("NOTIFY_CONSTRUCTOR(") != wxNOT_FOUND)
		||	(array[i].Find("NOTIFY_FUNCTION_CALL(") != wxNOT_FOUND)
		||	(array[i].Find("NOTIFY_DESTRUCTOR(") != wxNOT_FOUND)
		)
		array.RemoveAt(i,1);
	else
		i++;
}