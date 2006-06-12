generalisationID = GetUniqueID();
extendID = GetUniqueID();
includeID = GetUniqueID();

Connect(generalisationID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafUseCase::AddRelation));
Connect(extendID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafUseCase::AddRelation));
Connect(includeID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafUseCase::AddRelation));

myLabel = new wxTextCtrl(parent,-1,"",wxDefaultPosition,wxDefaultSize, wxTE_CENTRE | wxTE_MULTILINE );
myLabel->Hide();
labelOffset = wxPoint(-40,-25);
myLabel->SetSize(100,50);