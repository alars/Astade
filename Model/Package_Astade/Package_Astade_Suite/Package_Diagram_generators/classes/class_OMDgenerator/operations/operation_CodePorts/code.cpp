//~~ void CodePorts(int depth, const AdeClass* theClass, const wxString& nodename) [OMDgenerator] ~~

AdePorts* thePorts = theClass->GetPorts();

if (thePorts)
{
	for (AdeElementIterator it = thePorts->begin(); it != thePorts->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);
		AdePort* aPort = dynamic_cast<AdePort*>(anElement);
		wxASSERT_MSG(aPort, "the ports folder should only contain ports");
        
        IndentOutput(depth);
        std::cout << nodename << "_" << aPort->GetName() 
            << "[shape=plaintext, label=\"" << aPort->GetName() << "\", fontname = arial, fontsize=8]" << std::endl;
        
        IndentOutput(depth);
        if (aPort->IsDelegate())
        {
            std::cout << nodename << " -> " << nodename << "_" << aPort->GetName() << "[style=dotted, arrowhead=obox]" << std::endl;
        }
        else
        {
            std::cout << nodename << " -> " << nodename << "_" << aPort->GetName() << "[arrowhead=obox]" << std::endl;
        }
        
		delete anElement;
	}
    delete thePorts;
}

