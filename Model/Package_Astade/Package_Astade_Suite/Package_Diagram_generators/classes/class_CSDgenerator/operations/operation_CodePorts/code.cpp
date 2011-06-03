//~~ void CodePorts(const AdeClass* theClass) [CSDgenerator] ~~

AdePorts* thePorts = theClass->GetPorts();

if (thePorts)
{
	for (AdeElementIterator it = thePorts->begin(); it != thePorts->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);
		AdePort* aPort = dynamic_cast<AdePort*>(anElement);
		wxASSERT_MSG(aPort, "the ports folder should only contain ports");
        
        std::cout << aPort->GetName() << "[shape=plaintext, label=\"" << aPort->GetName() << "\", fontname = arial, fontsize=8]" << std::endl;
        
        if (aPort->IsDelegate())
        {
            std::cout << aPort->GetName() << " -> " << aPort->GetDelegationObject() 
                      << "[fontname=arial, fontsize=8, arrowhead=obox, style=dotted, arrowtail=obox, headlabel=\"" << aPort->GetDelegationPort() << "\"]" << std::endl;
        }
        else
        {
            std::cout << aPort->GetName() << " -> " << nodename << "[arrowhead=none, arrowtail=obox, lhead=\"cluster0\"]" << std::endl;
        }
        
		delete anElement;
	}
    delete thePorts;
}
