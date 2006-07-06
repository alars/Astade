wxPoint aPosition = event.GetPosition();
if (selectedNode)
{
	GrafVector borderPoint = selectedNode->GetBorderPoint(GrafVector(aPosition.x,aPosition.y));
	GrafVector oldBorderPoint = selectedNode->GetBorderPoint(GrafVector(lastMouseEvent.x,lastMouseEvent.y));

	wxRect damage1(aPosition,wxPoint(borderPoint.xCoord(),borderPoint.yCoord()));
	wxRect damage2(lastMouseEvent,wxPoint(oldBorderPoint.xCoord(),oldBorderPoint.yCoord()));

	damage1.Union(damage2);
	Refresh(true,&damage1);
}
lastMouseEvent = aPosition;