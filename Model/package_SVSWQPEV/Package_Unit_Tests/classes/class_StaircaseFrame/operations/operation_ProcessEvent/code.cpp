if (TakeEvent(event))
	return true;
else
	return wxFrame::ProcessEvent(event);