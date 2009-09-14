std::set<glRoundEdge*> myColleques;

for (std::set<glRoundEdge*>::iterator it = RoundEdgelist.begin(); it != RoundEdgelist.end(); it++)
{
	if ((&myEndNode == &((*it)->myEndNode)) && (&myStartNode == &((*it)->myStartNode)))
		myColleques.insert(*it);

	if ((&myEndNode == &((*it)->myStartNode)) && (&myStartNode == &((*it)->myEndNode)))
		myColleques.insert(*it);
}

const int widthincrement = 12;

//int minwidth =  -widthincrement  * (myColleques.size()+1);
int minwidth = -6;

for (std::set<glRoundEdge*>::iterator it = myColleques.begin(); it != myColleques.end(); it++)
{
//	if ((&myEndNode == &((*it)->myEndNode)) && (&myStartNode == &((*it)->myStartNode)))
		(*it)->width = minwidth;
//	else
//		(*it)->width = -minwidth;
	printf("minwidth = %d\n",minwidth);
	minwidth -= widthincrement;
}
