//~~ void Save(wxConfigBase& configObject) [scPerson] ~~

glNode::Save(configObject);
configObject.Write(wxS("ClassName"), wxS("person"));
configObject.Write(wxS("Label"), myLabel);
configObject.Write(wxS("Male"), male);
configObject.Write(wxS("Child"), child);

int Count = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); ++it)
{
  scRelation* aRelation = dynamic_cast<scRelation*>(*it);
  if (&(*it)->GetStartNode() == this && aRelation)
  {
      wxString aString;
      aString.Printf(wxS("Relation%03d"), ++Count);
      configObject.Write(aString, aRelation->GetEndNode().id);
  }
}
