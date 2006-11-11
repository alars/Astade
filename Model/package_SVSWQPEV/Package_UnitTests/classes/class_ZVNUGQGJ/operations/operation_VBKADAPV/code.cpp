if (!TakeEvent(event))
	return wxFrame::ProcessEvent(event);
else
	return true;