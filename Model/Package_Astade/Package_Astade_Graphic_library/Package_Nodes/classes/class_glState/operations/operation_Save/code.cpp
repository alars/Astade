glNode::Save(configObject);
configObject.Write("Label",myLabel);
configObject.Write("ClassName","state");

int transCount = 0;
for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
    if (&(*it)->GetStartNode() == this)
    {

        glTransition* aTransition = dynamic_cast<glTransition*>(*it);
       
        if (aTransition)
        {
            wxString aString;
            aString.Printf("Transition%03d",++transCount);
            configObject.Write(aString,aTransition->GetEndNode().id);
            configObject.SetPath(aString);
            aTransition->Save(configObject);
            configObject.SetPath("..");
        }

    }
    
int selftransCount = 0;
for (std::set<glSelfEdge*>::iterator it = mySelfEdges.begin(); it != mySelfEdges.end(); it++)
{
    glSelfTransition* aSelfTransition = dynamic_cast<glSelfTransition*>(*it);
   
    if (aSelfTransition)
    {
        wxString aString;
        aString.Printf("SelfTransition%03d",++selftransCount);
        configObject.SetPath(aString);
        aSelfTransition->Save(configObject);
        configObject.SetPath("..");
    }
}
