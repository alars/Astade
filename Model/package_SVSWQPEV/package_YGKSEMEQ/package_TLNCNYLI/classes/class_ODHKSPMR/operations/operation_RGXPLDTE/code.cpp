char Buffer[1000];

if (theMakeProcess)
{
	bool somethingRead = false;

	if (theMakeProcess->theMakeInputStream)
	{
		while (theMakeProcess->theMakeInputStream->CanRead())
		{
			myMakeOutput->SetNormalStyle();
			theMakeProcess->theMakeInputStream->Read(Buffer, sizeof(Buffer) - 1);
			Buffer[theMakeProcess->theMakeInputStream->LastRead()] = 0;
			*(myMakeOutput->TheEdit()) << Buffer;
			somethingRead = true;
		}
	}

	if (theMakeProcess->theMakeErrorStream)
	{
		while (theMakeProcess->theMakeErrorStream->CanRead())
		{
			myMakeOutput->SetErrorStyle();
			theMakeProcess->theMakeErrorStream->Read(Buffer, sizeof(Buffer) - 1);
			Buffer[theMakeProcess->theMakeErrorStream->LastRead()] = 0;
			*(myMakeOutput->TheEdit()) << Buffer;
			somethingRead = true;
		}
	}

	if (!somethingRead & theMakeProcess->alreadyTerminated)
	{
		if (theMakeProcess->exitCode)
		{
			myMakeOutput->SetErrorStyle();
			*(myMakeOutput->TheEdit())	<< "\n\n"
									<<	"***************************************\n"
									<<	"**        There are Errors !!!!      **\n"
									<<	"***************************************\n\n";
		}
		else
		{
			myMakeOutput->SetNormalStyle();
			*(myMakeOutput->TheEdit())	<< "\n\n"
									<<	"***************************************\n"
									<<	"**        Terminated successful      **\n"
									<<	"***************************************\n\n";
		}

		delete theMakeProcess;
		theMakeProcess = NULL;
	}
}

wxConfigBase* theConfig = wxConfigBase::Get();
int x,y;

GetPosition(&x,&y);

if (x > 0 && y > 0)
{
	theConfig->Write("Treeview/XPos",x);
	theConfig->Write("Treeview/YPos",y);

	GetSize(&x,&y);
	theConfig->Write("Treeview/XSize",x);
	theConfig->Write("Treeview/YSize",y);
}

myMakeOutput->GetPosition(&x,&y);

if (x > 0 && y > 0)
{
	theConfig->Write("MakeOutput/XPos",x);
	theConfig->Write("MakeOutput/YPos",y);

	myMakeOutput->GetSize(&x,&y);
	theConfig->Write("MakeOutput/XSize",x);
	theConfig->Write("MakeOutput/YSize",y);
}
