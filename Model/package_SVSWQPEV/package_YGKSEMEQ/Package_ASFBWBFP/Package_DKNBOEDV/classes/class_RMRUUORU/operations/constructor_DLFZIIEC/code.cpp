featuresID = GetUniqueID();

myLabel = new wxTextCtrl(parent,-1,"",wxDefaultPosition,wxDefaultSize, wxTE_CENTRE | wxTE_MULTILINE );
myLabel->Hide();
labelOffset = wxPoint(-40,-25);
myLabel->SetSize(100,50);