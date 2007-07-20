for (std::list<ACNode*>::iterator itN = myNodes.begin(); itN != myNodes.end(); itN++)
 	if (*itN == element)
 	{
 		std::list<ACNode*>::iterator next = myNodes.erase(itN);
		delete element;

 		if (next != myNodes.end())
 		{
 			element = *next;
 			myNodes.erase(next);
 			delete element;
 		}

		CalculateNodePositions();
		element = 0;
		return;
	}