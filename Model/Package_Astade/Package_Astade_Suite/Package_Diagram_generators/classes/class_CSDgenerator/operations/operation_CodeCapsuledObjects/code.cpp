//~~ void CodeCapsuledObjects(const AdeClass* theClass) [CSDgenerator] ~~

AdePorts* thePorts = theClass->GetPorts();
AdeConnections* theConnections = theClass->GetConnections();
std::set<wxString> theNodes;

if (thePorts)
{
	for (AdeElementIterator it = thePorts->begin(); it != thePorts->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);
		AdePort* aPort = dynamic_cast<AdePort*>(anElement);
		wxASSERT_MSG(aPort, wxS("the ports folder should only contain ports"));

        if (aPort->IsDelegate())
        {
            theNodes.insert(aPort->GetDelegationObject());
        }

		delete anElement;
	}
    delete thePorts;
}

if (theConnections)
{
	for (AdeElementIterator it = theConnections->begin(); it != theConnections->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);
		AdeConnection* aConnection = dynamic_cast<AdeConnection*>(anElement);
		wxASSERT_MSG(aConnection, wxS("the connections folder should only contain connections"));

        theNodes.insert(aConnection->GetInputObject());
        theNodes.insert(aConnection->GetOutputObject());

		delete anElement;
	}
}

for (std::set<wxString>::iterator it = theNodes.begin(); it != theNodes.end(); ++it)
{
    std::cout << it->utf8_str() << "[shape=box, label=\"" << it->utf8_str() << "\", fontname = arial, fontsize=10]" << std::endl;
}

if (theConnections)
{
	for (AdeElementIterator it = theConnections->begin(); it != theConnections->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);
		AdeConnection* aConnection = dynamic_cast<AdeConnection*>(anElement);
		wxASSERT_MSG(aConnection, wxS("the connections folder should only contain connections"));

        std::cout << aConnection->GetOutputObject().utf8_str() << " -> "
                  << aConnection->GetInputObject().utf8_str() << "[fontname = arial, fontsize=8, arrowhead=obox, arrowtail=obox, dir=both, "
                  << "taillabel=\"" << aConnection->GetOutputPort().utf8_str() << "\", "
                  << "headlabel=\"" << aConnection->GetInputPort().utf8_str() << "\"]" << std::endl;

		delete anElement;
	}
    delete theConnections;
}
