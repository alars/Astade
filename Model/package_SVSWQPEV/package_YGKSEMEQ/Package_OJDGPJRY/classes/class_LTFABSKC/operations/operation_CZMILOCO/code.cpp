for (std::list<ACNode*>::iterator itN = myNodes.begin(); itN != myNodes.end(); itN++)
 	if (*itN == element)
 	{
 		std::list<ACNode*>::iterator aNew = myNodes.insert(itN, newElement);

 		myNodes.insert(aNew, new ACConnectionNode);

		CalculateNodePositions();
		return;
	}