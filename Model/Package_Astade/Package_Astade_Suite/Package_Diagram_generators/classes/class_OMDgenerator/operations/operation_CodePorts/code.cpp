//~~ void CodePorts(int depth, const AdeClass* theClass, const wxString& nodename) [OMDgenerator] ~~

AdePorts* thePorts = theClass->GetPorts();

if (thePorts)
{
	for (AdeElementIterator it = thePorts->begin(); it != thePorts->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);
		AdePort* aPort = dynamic_cast<AdePort*>(anElement);
		wxASSERT_MSG(aPort, wxS("the ports folder should only contain ports"));

		IndentOutput(depth);
		std::cout << CleanName(nodename).utf8_str() << "_" << CleanName(aPort->GetName()).utf8_str()
			<< "[shape=plaintext, label=\""
			<< CleanName(aPort->GetName()).utf8_str()
			<< "\", fontname = arial, fontsize=8]"
			<< std::endl;

		IndentOutput(depth);
		if (aPort->IsDelegate())
		{
			std::cout << CleanName(nodename).utf8_str()
				<< " -> "
				<< CleanName(nodename).utf8_str() << "_" << CleanName(aPort->GetName()).utf8_str()
				<< "[style=dotted, arrowhead=obox]"
				<< std::endl;
		}
		else
		{
			std::cout << CleanName(nodename).utf8_str()
				<< " -> "
				<< CleanName(nodename).utf8_str() << "_" << CleanName(aPort->GetName()).utf8_str()
				<< "[arrowhead=obox]"
				<< std::endl;
		}

		delete anElement;
	}
	delete thePorts;
}
