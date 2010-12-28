//~~ void CodeCapsuledObjects(const AdeClass* theClass) [CSDgenerator] ~~

AdePorts* thePorts = theClass->GetPorts();
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
    
    for (std::set<wxString>::iterator it = theNodes.begin(); it != theNodes.end(); it++)
    {
        std::cout << *it << "[shape=box, label=\"" << *it << "\", fontname = arial, fontsize=10]" << std::endl;
    }
    
}

