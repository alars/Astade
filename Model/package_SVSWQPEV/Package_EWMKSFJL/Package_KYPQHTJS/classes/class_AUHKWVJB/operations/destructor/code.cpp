while (!myEdges.empty())
{
	(*myEdges.begin())->Refresh();
	delete (*myEdges.begin());
}