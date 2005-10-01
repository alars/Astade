myToolBar = CreateToolBar();

regenerateButton = new wxButton(myToolBar, ID_REGENERATE,  "Regenerate all" ,wxPoint(1,1),wxSize(180,20));

myToolBar->AddControl(regenerateButton);
myToolBar->Realize();