int xSize = 0;
int ySize = 0;

for (std::list<ACRow*>::iterator itR = myRows.begin(); itR != myRows.end(); itR++)
{
	std::list<ACNode*> aList = (*itR)->GetNodes();

	for (std::list<ACNode*>::iterator itN = aList.begin(); itN != aList.end(); itN++)
	{
 		wxPoint position = (*itN)->GetPosition();
 		int x,y;
 		(*itN)->GetSize(&x,&y);

 		if ((position.x + x) > xSize)
 			xSize = (position.x + x);

 		if ((position.y + y) > ySize)
 			ySize = (position.y + y);
 	}
}

SetScrollbars(20, 20, 50, 50);
SetVirtualSize(xSize,ySize);
Refresh();