while (!myNodes.empty())
{
	ACNode* aNode = myNodes.front();
	myNodes.pop_front();
	delete aNode;
}