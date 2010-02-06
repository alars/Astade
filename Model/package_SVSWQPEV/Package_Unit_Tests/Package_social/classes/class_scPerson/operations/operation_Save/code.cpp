glNode::Save(configObject);
configObject.Write("ClassName","person");
configObject.Write("Label",myLabel);
configObject.Write("Male",male);
configObject.Write("Child",child);

int Count = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
{
  scRelation* aRelation = dynamic_cast<scRelation*>(*it);
  if ((&(*it)->GetStartNode() == this) && (aRelation))
  {
      wxString aString;
      aString.Printf("Relation%03d",++Count);
      configObject.Write(aString,aRelation->GetEndNode().id);
  }
}
