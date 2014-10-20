//~~ void AddNotebookSizer(wxSizer* topSizer) [ResourceEdit] ~~

notebook = new wxNotebook(this, -1);
featurePanel = new wxPanel(notebook, -1);
annotationsPanel = new wxPanel(notebook, -1);
featurePanelSizer = new wxBoxSizer(wxVERTICAL);
wxBoxSizer* annotationPanelSizer = new wxBoxSizer(wxVERTICAL);

notebook->InsertPage(0,featurePanel,wxS("feature"));
notebook->InsertPage(1,annotationsPanel,wxS("annotations"));
featurePanel->SetSizer(featurePanelSizer);
annotationsPanel->SetSizer(annotationPanelSizer);

AnnotationField = new wxTextCtrl(annotationsPanel, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

AnnotationField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Annotations"), wxEmptyString));

annotationPanelSizer->Add(AnnotationField, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM | wxTOP, 10);

topSizer->Add(notebook, 3, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);
