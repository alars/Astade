for (std::list<ACRow*>::iterator itR = myRows.begin(); itR != myRows.end(); itR++)
	(*itR)->Erase(m_MenuNode);

Refresh();