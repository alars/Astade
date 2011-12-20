//~~ void Clear() [SeqDataBase] ~~
itsEvents.clear();

itsEvents.push_back(SeqEvent(wxNOT_FOUND,wxNOT_FOUND,ID_NOP,wxEmptyString,wxEmptyString,wxEmptyString));
itsEvents.push_back(SeqEvent(wxNOT_FOUND,wxNOT_FOUND,ID_NOP,wxEmptyString,wxEmptyString,wxEmptyString));
itsEvents.back().time = GetUpperBorder();

classes.Clear();
eventQueue.clear();
eventQueue.reserve(MAXCLASSCOUNT);
for (int i=0; i < MAXCLASSCOUNT; i++)
{
	std::list<int> e;
	eventQueue.push_back(e);
}

while (myEditMenu && myEditMenu->GetMenuItemCount() > 0)
{
	wxMenuItem* aItem = myEditMenu->FindItemByPosition(0);
	myEditMenu->Remove(aItem);
	delete aItem;
}


longestTimeStamp = 0;
