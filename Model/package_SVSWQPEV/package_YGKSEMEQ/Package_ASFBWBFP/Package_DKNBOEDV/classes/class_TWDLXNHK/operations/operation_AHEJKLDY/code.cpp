static int divisor = 10;

for (std::list<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
{
	(*it)->CalculatePosition();
}

divisor--;
if (divisor == 0)
{
	Refresh();
	divisor = 2;
}