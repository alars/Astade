//~~ void AddNotebookSizer(wxSizer* topSizer) [ResourceEdit] ~~

notebook = new wxNotebook(this, -1);
featurePanel = new wxPanel(notebook, -1);
annotationsPanel = new wxPanel(notebook, -1);
featurePanelSizer = new wxBoxSizer(wxVERTICAL);

notebook->InsertPage(0,featurePanel,wxS("feature"));
notebook->InsertPage(1,annotationsPanel,wxS("annotations"));
featurePanel->SetSizer(featurePanelSizer);

topSizer->Add(notebook, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);
