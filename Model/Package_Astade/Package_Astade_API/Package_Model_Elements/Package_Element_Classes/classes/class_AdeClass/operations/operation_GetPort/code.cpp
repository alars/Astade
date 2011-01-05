//~~ wxString GetPort(const wxString& portName) [AdeClass] ~~
wxString ret;
AdePorts* thePorts = GetPorts();

if (thePorts)
{
	for(AdeElementIterator it = thePorts->begin(); it != thePorts->end(); ++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();
		wxASSERT(aElement);
		AdePort* aPort = dynamic_cast<AdePort*>(aElement);
		wxASSERT_MSG(aRelation, "the ports folder should only contain ports");
        
        if (aPort->IsDelegate())
            ret = GetObjectPort(aPort->GetDelegationObject(), aPort->GetDelegationPort());
        else
            ret = portName;
        
		delete(aElement);
	}
    delete thePorts;
}

return ret;