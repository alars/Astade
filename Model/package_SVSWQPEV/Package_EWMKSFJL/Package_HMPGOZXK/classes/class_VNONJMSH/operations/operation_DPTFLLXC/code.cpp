std::set<glRoundEdge*> myColleques;

for (std::set<glRoundEdge*>::iterator it = RoundEdgelist.begin(); it != RoundEdgelist.end(); it++)
{
	if ((&myEndNode == &((*it)->myEndNode)) && (&myStartNode == &((*it)->myStartNode)))
		myColleques.insert(*it);

	if ((&myEndNode == &((*it)->myStartNode)) && (&myStartNode == &((*it)->myEndNode)))
		myColleques.insert(*it);
}

const int widthincrement = 12;

int minwidth =  (widthincrement/2) - (widthincrement * (myColleques.size()/2));

for (std::set<glRoundEdge*>::iterator it = myColleques.begin(); it != myColleques.end(); it++)
{
	(*it)->lastEndPoint = glVector();
	(*it)->lastStartPoint = glVector();
	(*it)->Refresh();
	if ((&myEndNode == &((*it)->myEndNode)) && (&myStartNode == &((*it)->myStartNode)))
		(*it)->width = minwidth;
	else
		(*it)->width = -minwidth;
	(*it)->Refresh();
	minwidth += widthincrement;
}
