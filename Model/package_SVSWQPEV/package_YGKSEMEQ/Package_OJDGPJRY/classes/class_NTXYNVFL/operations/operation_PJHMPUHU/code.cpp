if (m_MenuNode==0)
	return;

ACDecisionNode* aDecisionNode = new ACDecisionNode;

for (std::list<ACRow*>::iterator itR = myRows.begin(); itR != myRows.end(); itR++)
	(*itR)->Insert(m_MenuNode, aDecisionNode);

CalculateVirtualSize();