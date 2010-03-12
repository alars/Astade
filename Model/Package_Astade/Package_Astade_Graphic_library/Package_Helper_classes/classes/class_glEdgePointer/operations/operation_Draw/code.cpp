if (mySourceNode.isInElement(myParent->getMousePosition()))
	return;

if (!myParent->getMouseIn())
	return;

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLACK"),1,wxLONG_DASH));
dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), myParent->getMousePosition().xCoord(), myParent->getMousePosition().yCoord());
