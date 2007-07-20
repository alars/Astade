if (m_MenuNode==0)
	return;

ACActivityNode* aActivityNode = new ACActivityNode;

for (std::list<ACRow*>::iterator itR = myRows.begin(); itR != myRows.end(); itR++)
	(*itR)->Insert(m_MenuNode, aActivityNode);

CalculateVirtualSize();