generalisationID = GetUniqueID();
extendID = GetUniqueID();
includeID = GetUniqueID();
deleteExtentionID = GetUniqueID(50); // Node should never get more than 50 Extentions
deleteIncludeID = GetUniqueID(50); // Node should never get more than 50 Includes
deleteSpecialisationID = GetUniqueID(50); // Node should never get more than 50 Specialisations

Connect(deleteExtentionID, deleteExtentionID+49, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafUseCase::DeleteRelation));
Connect(deleteIncludeID, deleteIncludeID+49, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafUseCase::DeleteRelation));
Connect(deleteSpecialisationID, deleteSpecialisationID+49, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafUseCase::DeleteRelation));

Connect(generalisationID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafUseCase::AddRelation));
Connect(extendID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafUseCase::AddRelation));
Connect(includeID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafUseCase::AddRelation));

myLabel = new wxTextCtrl(parent,-1,"",wxDefaultPosition,wxDefaultSize, wxTE_CENTRE | wxTE_MULTILINE );
myLabel->Hide();
labelOffset = wxPoint(-40,-25);
myLabel->SetSize(100,50);