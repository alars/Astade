//~~ void Save(wxConfigBase& configObject) [glArtefact] ~~

glNode::Save(configObject);
configObject.Write(wxS("Label"), myLabel);
configObject.Write(wxS("ClassName"), wxS("artefact"));

int artefactCount = 0;
int dependencyCount = 0;
int compositionCount = 0;

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
        
        glArtefactDependency* aDependency = dynamic_cast<glArtefactDependency*>(*it);
       
        if (aDependency)
        {
            wxString aString;
            aString.Printf(wxS("ArtefactDependency%03d"), ++dependencyCount);
            configObject.Write(aString, aDependency->GetEndNode().id);
        }

        glArtefactComposition* aComposition = dynamic_cast<glArtefactComposition*>(*it);
       
        if (aComposition)
        {
            wxString aString;
            aString.Printf(wxS("ArtefactComposition%03d"), ++compositionCount);
            configObject.Write(aString, aComposition->GetEndNode().id);
        }
    }
