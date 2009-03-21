while (!myEdges.empty())
{
	(*myEdges.begin())->Refresh();
	delete (*myEdges.begin());
}

delete myGravityArea;