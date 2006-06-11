featuresID = GetUniqueID();
hasAssociationID = GetUniqueID();

Connect(hasAssociationID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafActor::AddAssociation));

myLabel = new wxTextCtrl(parent,-1,"",wxDefaultPosition,wxDefaultSize, wxTE_CENTRE );
myLabel->Hide();
labelOffset = wxPoint(-40,15);
myLabel->SetSize(80,20);