//~~ void CodePortConnections(std::ofstream& out) [GeneratorBase] ~~

AdeConnections* theConnections = source->GetConnections();

if (theConnections)
{
    out << "\n\t//connecting the inner ports" << std::endl;
	for (AdeElementIterator it = theConnections->begin(); it != theConnections->end(); ++it)
	{
        AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);
		AdeConnection* aConnection = dynamic_cast<AdeConnection*>(anElement);
		wxASSERT_MSG(aConnection, "the Connections folder should only contain connections");

        wxString InputObject = aConnection->GetInputObject();
        wxString InputPort = aConnection->GetInputPort();
        wxString OutputObject = aConnection->GetOutputObject();
        wxString OutputPort = aConnection->GetOutputPort();

        if (source->codingLanguage() == CODE_C)
        {
            out << "\tCONNECT_PORTS(" << "me->" << source->GetObject(InputObject, InputPort).utf8_str() << ", "
                                      << "me->" << source->GetObjectPort(InputObject, InputPort).utf8_str() << ", "
                                      << "me->" << source->GetObject(OutputObject, OutputPort).utf8_str() << ", "
                                      << "me->" << source->GetObjectPort(OutputObject, OutputPort).utf8_str() << ");" << std::endl;
        }
        else
        {
            out << "\tCONNECT_PORTS(" << source->GetObject(InputObject, InputPort).utf8_str() << ", "
                                      << source->GetObjectPort(InputObject, InputPort).utf8_str() << ", "
                                      << source->GetObject(OutputObject, OutputPort).utf8_str() << ", "
                                      << source->GetObjectPort(OutputObject, OutputPort).utf8_str() << ");" << std::endl;
        }

		delete anElement;
	}
    delete theConnections;
}
