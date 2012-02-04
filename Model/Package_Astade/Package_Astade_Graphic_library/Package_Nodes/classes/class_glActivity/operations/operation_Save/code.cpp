//~~ void Save(wxConfigBase& configObject) [glActivity] ~~

glNode::Save(configObject);
configObject.Write("Label",myLabel);
configObject.Write("ClassName","activity");

int useCount = 0;
int provideCount = 0;
int ComponentUseCount = 0;

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

        glIncludeExtend* aComponent = dynamic_cast<glIncludeExtend*>(*it);
       
        if (aComponent)
        {
            wxString aString;
            aString.Printf("ComponentUse%03d",++ComponentUseCount);
            configObject.Write(aString,aComponent->GetEndNode().id);
        }
    }