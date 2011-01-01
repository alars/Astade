//~~ void CodePortInit(std::ofstream& out) [GeneratorBase] ~~
AdePorts* thePorts = source->GetPorts();

if (thePorts)
{
    out << "\n\t//initialize the specified ports of that class" << std::endl;
	for(AdeElementIterator it = thePorts->begin(); it != thePorts->end(); ++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();
		wxASSERT(aElement);
		AdePort* aPort = dynamic_cast<AdePort*>(aElement);
		wxASSERT_MSG(aPort, "the ports folder should only contain ports");
        
        if (aPort->IsDelegate())
        {
            if (aPort->IsInput())
            {
                out << "\tINITIALIZE_INPUT_DELEGATE(" << aPort->GetName() << ", " 
                                                      << aPort->GetDelegationObject() << ", " 
                                                      << aPort->GetDelegationPort() << ");" << std::endl;
            }
            else
            {
                 out << "\tINITIALIZE_OUTPUT_DELEGATE(" << aPort->GetName() << ", " 
                                                        << aPort->GetDelegationObject() << ", " 
                                                        << aPort->GetDelegationPort() << ");" << std::endl;
             }
        }
        else
        {
            if (aPort->IsInput())
            {
                out << "\tINITIALIZE_INPUT_PORT(" << aPort->GetName() << ");" << std::endl;
            }
            else
            {
                out << "\tINITIALIZE_OUTPUT_PORT(" << aPort->GetName() << ");" << std::endl;
            }
        }
        
		delete(aElement);
	}
    delete thePorts;
}

