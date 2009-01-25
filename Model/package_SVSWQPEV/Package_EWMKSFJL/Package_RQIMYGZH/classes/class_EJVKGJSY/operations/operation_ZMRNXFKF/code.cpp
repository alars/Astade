if (mySourceNode.isInElement(mousePosition))
	return;

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLACK"),1,wxLONG_DASH));
dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), mousePosition.xCoord(), mousePosition.yCoord());