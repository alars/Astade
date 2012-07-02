//~~ void CodePorts(const AdeClass* theClass) [CSDgenerator] ~~

AdePorts* thePorts = theClass->GetPorts();

if (thePorts)
{
	for (AdeElementIterator it = thePorts->begin(); it != thePorts->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);
		AdePort* aPort = dynamic_cast<AdePort*>(anElement);
		wxASSERT_MSG(aPort, wxS("the ports folder should only contain ports"));

        std::cout << aPort->GetName().utf8_str() << "[shape=plaintext, label=\"" << aPort->GetName().utf8_str() << "\", fontname = arial, fontsize=8]" << std::endl;

        if (aPort->IsDelegate())
        {
            std::cout << aPort->GetName().utf8_str() << " -> " << aPort->GetDelegationObject().utf8_str()
                      << "[fontname=arial, fontsize=8, arrowhead=obox, style=dotted, arrowtail=obox, headlabel=\"" << aPort->GetDelegationPort().utf8_str() << "\"]" << std::endl;
        }
        else
        {
            std::cout << aPort->GetName().utf8_str() << " -> " << nodename.utf8_str() << "[arrowhead=none, arrowtail=obox, lhead=\"cluster0\"]" << std::endl;
        }

		delete anElement;
	}
    delete thePorts;
}
