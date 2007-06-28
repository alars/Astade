wxPoint aPosition = event.GetPosition();
bool refreshNeeded = false;

for (std::list<ACRow*>::iterator itR = myRows.begin(); itR != myRows.end(); itR++)
{
	std::list<ACNode*> aList = (*itR)->GetNodes();

	for (std::list<ACNode*>::iterator itN = aList.begin(); itN != aList.end(); itN++)
	{
 		bool mouseInThisNode = (*itN)->IsInArea(aPosition);
 		bool somethingChanged = (*itN)->SetMouseOver(mouseInThisNode);
 		if (somethingChanged)
 		{
 			refreshNeeded = true;
 			if (mouseInThisNode)
 				m_MouseOverNode = *itN;
 			else
 				m_MouseOverNode = NULL;
 		}
 	}
}

if (refreshNeeded)
	Refresh();