generalisationID = GetUniqueID();
hasAssociationID = GetUniqueID();
deleteAssiciationID = GetUniqueID(50); // Node should never get more than 50 Associations
deleteSpecialisationID = GetUniqueID(50); // Node should never get more than 50 Specialisations

Connect(hasAssociationID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafActor::AddAssociation));
Connect(deleteAssiciationID, deleteAssiciationID+49, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafActor::DeleteAssociation));
Connect(deleteSpecialisationID, deleteSpecialisationID+49, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafActor::DeleteAssociation));
Connect(generalisationID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafActor::AddAssociation));

myLabel = new wxTextCtrl(parent,-1,"",wxDefaultPosition,wxDefaultSize, wxTE_CENTRE );
myLabel->Hide();
labelOffset = wxPoint(-40,15);
myLabel->SetSize(80,20);