if (mySourceNode.isInElement(myParent->mousePosition))
	return;

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLACK"),1,wxLONG_DASH));
dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), myParent->mousePosition.xCoord(), myParent->mousePosition.yCoord());