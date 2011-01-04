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

        out << "\tCONNECT_INPUT_TO_OUTPUT(" << aConnection->GetInputObject() << ", " 
                                            << aConnection->GetInputPort() << ", " 
                                            << aConnection->GetOutputObject() << ", " 
                                            << aConnection->GetOutputPort() << ");" << std::endl;
        
		delete(aElement);
	}
    delete theConnections;
}

