featuresID = GetUniqueID();
hasAssociationID = GetUniqueID();

Connect(hasAssociationID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafActor::AddAssociation));

label = "Customer";