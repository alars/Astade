//~~ void declarePorts(std::ofstream& out) [GeneratorBase] ~~
AdePorts* thePorts = source->GetPorts();

if (thePorts)
{
    out << "\n\t//declare the specified ports of that class" << std::endl;
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
                out << "\tDECLARE_INPUT_DELEGATE(" << aPort->GetName() << ");" << std::endl;
            }
            else
            {
                out << "\tDECLARE_OUTPUT_DELEGATE(" << aPort->GetName() << ");" << std::endl;
            }
        }
        else
        {
            if (aPort->IsInput())
            {
                out << "\tDECLARE_INPUT_PORT(" << aPort->GetName() << ");" << std::endl;
            }
            else
            {
                out << "\tDECLARE_OUTPUT_PORT(" << aPort->GetName() << ");" << std::endl;
            }
        }
        
		delete(aElement);
	}
    delete thePorts;
}

