//~~ void CodeCapsuledObjects(const AdeClass* theClass) [CSDgenerator] ~~

AdePorts* thePorts = theClass->GetPorts();
AdeConnections* theConnections = theClass->GetConnections();
std::set<wxString> theNodes;

if (thePorts)
{
	for(AdeElementIterator it = thePorts->begin(); it != thePorts->end(); ++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();
		wxASSERT(aElement);
		AdePort* aPort = dynamic_cast<AdePort*>(aElement);
		wxASSERT_MSG(aPort, "the ports folder should only contain ports");
        
        if (aPort->IsDelegate())
        {
            theNodes.insert(aPort->GetDelegationObject());
        }
        
		delete(aElement);
	}
    delete thePorts;
}
    
if (theConnections)
{
	for(AdeElementIterator it = theConnections->begin(); it != theConnections->end(); ++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();
		wxASSERT(aElement);
		AdeConnection* aConnection = dynamic_cast<AdeConnection*>(aElement);
		wxASSERT_MSG(aConnection, "the connections folder should only contain connections");
        
        theNodes.insert(aConnection->GetInputObject());
        theNodes.insert(aConnection->GetOutputObject());
        
		delete(aElement);
	}
}
    
for (std::set<wxString>::iterator it = theNodes.begin(); it != theNodes.end(); it++)
{
    std::cout << *it << "[shape=box, label=\"" << *it << "\", fontname = arial, fontsize=10]" << std::endl;
}

if (theConnections)
{
	for(AdeElementIterator it = theConnections->begin(); it != theConnections->end(); ++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();
		wxASSERT(aElement);
		AdeConnection* aConnection = dynamic_cast<AdeConnection*>(aElement);
		wxASSERT_MSG(aConnection, "the connections folder should only contain connections");
        
        std::cout << aConnection->GetOutputObject() << " -> " 
                  << aConnection->GetInputObject() << "[fontname = arial, fontsize=8, arrowhead=obox, arrowtail=obox, "
                  << "taillabel=\"" << aConnection->GetOutputPort() << "\", "
                  << "headlabel=\"" << aConnection->GetInputPort() << "\"]" << std::endl;
        
		delete(aElement);
	}
    delete theConnections;
}

