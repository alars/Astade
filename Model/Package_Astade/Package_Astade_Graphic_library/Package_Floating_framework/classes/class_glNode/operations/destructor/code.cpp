//~~ ~glNode() [glNode] ~~

while (!myEdges.empty())
{
	(*myEdges.begin())->Refresh();
	delete *myEdges.begin();
}

while (!mySelfEdges.empty())
	delete *mySelfEdges.begin();

delete myGravityArea;
