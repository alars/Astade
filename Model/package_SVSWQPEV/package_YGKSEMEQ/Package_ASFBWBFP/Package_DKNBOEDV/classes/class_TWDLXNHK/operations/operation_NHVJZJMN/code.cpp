while (!myGrafNodes.empty())
{
	GrafNode* aNode = *(myGrafNodes.begin());
	delete aNode;
}