//~~ void Save(wxConfigBase& configObject) [glActivity] ~~

glNode::Save(configObject);
configObject.Write(wxS("Label"), myLabel);
configObject.Write(wxS("ClassName"), wxS("activity"));

int artefactCount = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); ++it)
    if (&(*it)->GetStartNode() == this)
    {
        glCreateArtefact* anArtefact = dynamic_cast<glCreateArtefact*>(*it);
       
        if (anArtefact)
        {
            wxString aString;
            aString.Printf(wxS("CreateArtefact%03d"), ++artefactCount);
            configObject.Write(aString, anArtefact->GetEndNode().id);
        }
    }
