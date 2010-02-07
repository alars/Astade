Refresh();
AddMenuSeparator();
AddMenuFunction("Dependancy",wxCommandEventHandler(glSelfRelation::OnDependancy));
AddMenuFunction("Association",wxCommandEventHandler(glSelfRelation::OnAssociation));
AddMenuFunction("Aggregation",wxCommandEventHandler(glSelfRelation::OnAggregation));
AddMenuFunction("Composition",wxCommandEventHandler(glSelfRelation::OnComposition));
AddMenuSeparator();
AddMenuFunction("End point mult",wxCommandEventHandler(glSelfRelation::OnEndMult));
AddMenuFunction("Start point mult",wxCommandEventHandler(glSelfRelation::OnStartMult));
