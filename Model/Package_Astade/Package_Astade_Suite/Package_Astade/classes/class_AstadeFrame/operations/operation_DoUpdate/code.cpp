//~~ void DoUpdate(wxUpdateUIEvent& event) [AstadeFrame] ~~

if (rightMouseClickCount)
	return;

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
			*(myMakeOutput->TheEdit()) << wxString(Buffer, wxConvAuto());
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
			*(myMakeOutput->TheEdit()) << wxString(Buffer, wxConvAuto());
			somethingRead = true;
		}
	}

	if (!somethingRead && theMakeProcess->alreadyTerminated)
	{
		if (theMakeProcess->exitCode)
		{
			myMakeOutput->SetErrorStyle();
			*(myMakeOutput->TheEdit()) << wxS("\n\n")
					<< wxS("***************************************\n")
					<< wxS("**        There are Errors !!!!      **\n")
					<< wxS("***************************************\n\n");
		}
		else
		{
			myMakeOutput->SetNormalStyle();
			*(myMakeOutput->TheEdit()) << wxS("\n\n")
					<< wxS("***************************************\n")
					<< wxS("**        Terminated successful      **\n")
					<< wxS("***************************************\n\n");
		}

		delete theMakeProcess;
		theMakeProcess = NULL;
	}
}

wxConfigBase* theConfig = wxConfigBase::Get();
int x, y;

GetPosition(&x, &y);
theConfig->Write(wxS("Treeview/XPos"), x);
theConfig->Write(wxS("Treeview/YPos"), y);

GetSize(&x, &y);
theConfig->Write(wxS("Treeview/XSize"), x);
theConfig->Write(wxS("Treeview/YSize"), y);

myMakeOutput->GetPosition(&x, &y);
theConfig->Write(wxS("MakeOutput/XPos"), x);
theConfig->Write(wxS("MakeOutput/YPos"), y);

myMakeOutput->GetSize(&x, &y);
theConfig->Write(wxS("MakeOutput/XSize"), x);
theConfig->Write(wxS("MakeOutput/YSize"), y);
