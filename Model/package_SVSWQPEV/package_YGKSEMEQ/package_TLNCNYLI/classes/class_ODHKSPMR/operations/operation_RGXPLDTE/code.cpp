char Buffer[1000];

if (theMakeProcess)
{
	bool somethingRead = false;

	if (theMakeProcess->theMakeInputStream)
	{
		while (theMakeProcess->theMakeInputStream->CanRead())
		{
			myMakeOutput.SetNormalStyle();
			theMakeProcess->theMakeInputStream->Read(Buffer,sizeof(Buffer));
			Buffer[theMakeProcess->theMakeInputStream->LastRead()] = 0;
			myMakeOutput.theEdit << Buffer;
			somethingRead = true;
		}
	}

	if (theMakeProcess->theMakeErrorStream)
	{
		while (theMakeProcess->theMakeErrorStream->CanRead())
		{
			myMakeOutput.SetErrorStyle();
			theMakeProcess->theMakeErrorStream->Read(Buffer,sizeof(Buffer));
			Buffer[theMakeProcess->theMakeErrorStream->LastRead()] = 0;
			myMakeOutput.theEdit << Buffer;
			somethingRead = true;
		}
	}

	if (!somethingRead & theMakeProcess->alreadyTerminated)
	{
		if (theMakeProcess->exitCode)
		{
			myMakeOutput.SetErrorStyle();
			myMakeOutput.theEdit << "\n\n"
								 <<	"***************************************\n"
								 <<	"**        There are Errors !!!!      **\n"
								 <<	"***************************************\n\n";
		}
		else
		{
			myMakeOutput.SetNormalStyle();
			myMakeOutput.theEdit << "\n\n"
								 <<	"***************************************\n"
								 <<	"**        Terminated successful      **\n"
								 <<	"***************************************\n\n";
		}

		delete theMakeProcess;
		theMakeProcess = NULL;
	}
}

if (!myTree->theUpdateItemList.empty())
{
	wxTreeItemId aID = myTree->theUpdateItemList.front();
	myTree->theUpdateItemList.pop_front();
	myTree->DoUpdateItem(aID);
}
