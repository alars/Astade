//~~ wxString GetPort(const wxString& portName) [AdeClass] ~~

wxString ret;
AdePorts* thePorts = GetPorts();

if (thePorts)
{
    for(AdeElementIterator it = thePorts->begin(); it != thePorts->end(); ++it)
    {
        AdeModelElement* anElement = it.CreateNewElement();
        wxASSERT(anElement);
        AdePort* aPort = dynamic_cast<AdePort*>(anElement);
        wxASSERT_MSG(aPort, "the ports folder should only contain ports");
        
        if (portName == aPort->GetName())
        {
            if (aPort->IsDelegate())
                ret = GetObjectPort(aPort->GetDelegationObject(), aPort->GetDelegationPort());
            else
                ret = portName;
        }
        
        delete anElement;
    }
    delete thePorts;
}

return ret;
