//~~ void SaveDrawIo(std::ofstream& cr) [glNode] ~~

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); ++it)
{
    if (&(*it)->GetStartNode() == this)
        (*it)->SaveDrawIo(cr);
}

