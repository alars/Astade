std::set<glRoundEdge*> myColleques;

for (std::set<glRoundEdge*>::iterator it = RoundEdgelist.begin(); it != RoundEdgelist.end(); it++)
{
	if ((&myEndNode == &((*it)->myEndNode)) && (&myStartNode == &((*it)->myStartNode)))
		myColleques.insert(*it);

	if ((&myEndNode == &((*it)->myStartNode)) && (&myStartNode == &((*it)->myEndNode)))
		myColleques.insert(*it);
}

/* dont't do that at the moment, I think it looks better with round edges
if (myColleques.size() == 1)
{
	(*myColleques.begin())->width = 0;
	(*myColleques.begin())->Refresh();
	return;
}
*/

const int widthincrement = 8 + (100 / (myColleques.size()+1));

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
