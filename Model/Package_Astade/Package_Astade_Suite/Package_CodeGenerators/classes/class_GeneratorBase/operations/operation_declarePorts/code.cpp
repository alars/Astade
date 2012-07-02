//~~ void declarePorts(std::ofstream& out) [GeneratorBase] ~~

AdePorts* thePorts = source->GetPorts();
if (thePorts)
{
    out << "\n\t//declare the specified ports of that class" << std::endl;
	for (AdeElementIterator it = thePorts->begin(); it != thePorts->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);
		AdePort* aPort = dynamic_cast<AdePort*>(anElement);
		wxASSERT_MSG(aPort, "the ports folder should only contain ports");
        
        if (!aPort->IsDelegate())
            out << "\tDECLARE_PORT(" << aPort->GetName().utf8_str() << ");" << std::endl;
        
		delete anElement;
	}
    delete thePorts;
}
