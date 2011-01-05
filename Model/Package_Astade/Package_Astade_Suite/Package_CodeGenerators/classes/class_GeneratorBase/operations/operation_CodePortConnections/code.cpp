//~~ void CodePortConnections(std::ofstream& out) [GeneratorBase] ~~
AdeConnections* theConnections = source->GetConnections();

if (theConnections)
{
    out << "\n\t//connecting the inner ports" << std::endl;
	for(AdeElementIterator it = theConnections->begin(); it != theConnections->end(); ++it)
	{
        AdeModelElement* aElement = it.CreateNewElement();
		wxASSERT(aElement);
		AdeConnection* aConnection = dynamic_cast<AdeConnection*>(aElement);
		wxASSERT_MSG(aConnection, "the Connections folder should only contain connections");

        wxString InputObject = aConnection->GetInputObject();
        wxString InputPort = aConnection->GetInputPort();
        wxString OutputObject = aConnection->GetOutputObject();
        wxString OutputPort = aConnection->GetOutputPort();
        
        out << "\tCONNECT_PORTS(" << source->GetObject(InputObject, InputPort) << ", " 
                                  << source->GetObjectPort(InputObject, InputPort) << ", " 
                                  << source->GetObject(OutputObject, OutputPort) << ", " 
                                  << source->GetObjectPort(OutputObject, OutputPort) << ");" << std::endl;
        

		delete(aElement);

	}
    delete theConnections;
}

