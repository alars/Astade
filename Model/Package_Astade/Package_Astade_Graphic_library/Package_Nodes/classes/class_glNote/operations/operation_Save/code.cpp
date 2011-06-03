//~~ void Save(wxConfigBase& configObject) [glNote] ~~

glNode::Save(configObject);
configObject.Write("Label",myLabel);
configObject.Write("ClassName","note");

int attachCount = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); ++it)
    if (&(*it)->GetStartNode() == this)
    {
        glAttach* anAttach = dynamic_cast<glAttach*>(*it);
        
        if (anAttach)
        {
            wxString aString;
            aString.Printf("Attach%03d", ++attachCount);
            configObject.Write(aString, anAttach->GetEndNode().id);
        }
    }
