//~~ void Save(wxConfigBase& configObject) [glUsecase] ~~

glNode::Save(configObject);
configObject.Write("Label",myLabel);
configObject.Write("ClassName","usecase");

int specialisationCount = 0;
int extendCount = 0;
int includeCount = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); ++it)
    if (&(*it)->GetStartNode() == this)
    {
        glIncludeExtend* anIncludeExtend = dynamic_cast<glIncludeExtend*>(*it);
        
        if (anIncludeExtend)
        {
            wxString aString;
            if (anIncludeExtend->isInclude())
                aString.Printf("Include%03d", ++includeCount);
            else
                aString.Printf("Extention%03d", ++extendCount);
            configObject.Write(aString, anIncludeExtend->GetEndNode().id);
        }

        glSpecialize* aSpecialisation = dynamic_cast<glSpecialize*>(*it);
        
        if (aSpecialisation)
        {
            wxString aString;
            aString.Printf("Superclass%03d", ++specialisationCount);
            configObject.Write(aString, aSpecialisation->GetEndNode().id);
        }
    }
