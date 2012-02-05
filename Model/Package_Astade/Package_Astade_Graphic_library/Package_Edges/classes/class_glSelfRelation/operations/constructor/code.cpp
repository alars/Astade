//~~ glSelfRelation(glGraphicPanel& panel, glNode& parent, glVector absPosition) [glSelfRelation] ~~

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("Dependancy"), wxCommandEventHandler(glSelfRelation::OnDependancy));
AddMenuFunction(wxS("Association"), wxCommandEventHandler(glSelfRelation::OnAssociation));
AddMenuFunction(wxS("Aggregation"), wxCommandEventHandler(glSelfRelation::OnAggregation));
AddMenuFunction(wxS("Composition"), wxCommandEventHandler(glSelfRelation::OnComposition));
AddMenuSeparator();
AddMenuFunction(wxS("End point mult"), wxCommandEventHandler(glSelfRelation::OnEndMult));
AddMenuFunction(wxS("Start point mult"), wxCommandEventHandler(glSelfRelation::OnStartMult));
