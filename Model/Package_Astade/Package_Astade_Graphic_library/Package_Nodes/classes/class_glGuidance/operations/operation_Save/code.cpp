//~~ void Save(wxConfigBase& configObject) [glGuidance] ~~

glNode::Save(configObject);
configObject.Write(wxS("ClassName"), wxS("guidance"));
configObject.Write(wxS("Label"), myLabel);

int attachCount = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); ++it)
    if (&(*it)->GetStartNode() == this)
    {
        glAttach* anAttach = dynamic_cast<glAttach*>(*it);
        
        if (anAttach)
        {
            wxString aString;
            aString.Printf(wxS("Attach%03d"), ++attachCount);
            configObject.Write(aString, anAttach->GetEndNode().id);
        }
    }
