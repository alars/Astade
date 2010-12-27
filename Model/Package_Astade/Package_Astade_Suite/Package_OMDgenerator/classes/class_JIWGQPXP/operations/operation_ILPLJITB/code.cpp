//~~ void CodePorts(const AdeClass* theClass) [CSDgenerator] ~~

AdePorts* thePorts = theClass->GetPorts();

if (thePorts)
{
	for(AdeElementIterator it = thePorts->begin(); it != thePorts->end(); ++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();
		wxASSERT(aElement);
		AdePort* aPort = dynamic_cast<AdePort*>(aElement);
		wxASSERT_MSG(aPort, "the ports folder should only contain ports");
        
        std::cout << aPort->GetName() << "[shape=plaintext, label=\"" << aPort->GetName() << "\", fontname = arial, fontsize=8]" << std::endl;
        
        if (aPort->IsDelegate())
        {
            if (aPort->IsInput())
            {
                std::cout << aPort->GetName() << " -> " << nodename << "[arrowhead=none, style=dotted, arrowtail=box, lhead=\"cluster0\"]" << std::endl;
            }
            else
            {
                std::cout << aPort->GetName() << " -> " << nodename << "[arrowhead=none, style=dotted, arrowtail=obox, lhead=\"cluster0\"]" << std::endl;
            }
        }
        else
        {
            if (aPort->IsInput())
            {
                std::cout << aPort->GetName() << " -> " << nodename << "[arrowhead=none, arrowtail=box, lhead=\"cluster0\"]" << std::endl;
            }
            else
            {
                std::cout << aPort->GetName() << " -> " << nodename << "[arrowhead=none, arrowtail=obox, lhead=\"cluster0\"]" << std::endl;
            }
        }
        
		delete(aElement);
	}
    delete thePorts;
}

