char Buffer[1000];


if (theMakeInputStream)
{
	while (theMakeInputStream->CanRead())
	{
		theMakeInputStream->Read(Buffer,sizeof(Buffer));
		Buffer[theMakeInputStream->LastRead()] = 0;
		myMakeOutput.theEdit << Buffer;
	}
}

if (theMakeErrorStream)
{
	while (theMakeErrorStream->CanRead())
	{
		theMakeErrorStream->Read(Buffer,sizeof(Buffer));
		Buffer[theMakeErrorStream->LastRead()] = 0;
		myMakeOutput.theEdit << Buffer;
	}
}


if (!myTree->theUpdateItemList.empty())
{
	wxTreeItemId aID = myTree->theUpdateItemList.front();
	myTree->theUpdateItemList.pop_front();
	myTree->DoUpdateItem(aID);
}
