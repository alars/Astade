//~~ void Save(wxConfigBase& configObject) [glComponent] ~~

glNode::Save(configObject);
configObject.Write("Label",myLabel);
configObject.Write("ClassName","component");

int useCount = 0;
int provideCount = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); ++it)
    if (&(*it)->GetStartNode() == this)
    {

        glUseInterface* aUseInterface = dynamic_cast<glUseInterface*>(*it);
       
        if (aUseInterface)
        {
            wxString aString;
            aString.Printf("InterfaceUse%03d",++useCount);
            configObject.Write(aString,aUseInterface->GetEndNode().id);
        }

        glProvideInterface* aProvideInterface = dynamic_cast<glProvideInterface*>(*it);
       
        if (aProvideInterface)
        {
            wxString aString;
            aString.Printf("InterfaceProvide%03d",++provideCount);
            configObject.Write(aString,aProvideInterface->GetEndNode().id);
        }
    }
