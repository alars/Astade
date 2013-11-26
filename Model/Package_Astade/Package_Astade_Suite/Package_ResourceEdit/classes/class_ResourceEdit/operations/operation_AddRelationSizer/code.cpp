//~~ void AddRelationSizer(wxSizer* topSizer) [ResourceEdit] ~~
wxBoxSizer *relations = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(relations, 0, wxEXPAND|wxRIGHT|wxLEFT, 10);

wxArrayString arrayStringFor_WxComboBox1;
arrayStringFor_WxComboBox1.Add(wxS("ImplementationDependency"));
arrayStringFor_WxComboBox1.Add(wxS("SpecificationDependency"));
arrayStringFor_WxComboBox1.Add(wxS("Friend"));
arrayStringFor_WxComboBox1.Add(wxS("Association"));
arrayStringFor_WxComboBox1.Add(wxS("Aggregation"));
arrayStringFor_WxComboBox1.Add(wxS("Composition"));
arrayStringFor_WxComboBox1.Add(wxS("Generalization"));

AggregationType = new wxComboBox(this, ID_AGGREGATIONTYPE, wxEmptyString, wxDefaultPosition, wxDefaultSize, arrayStringFor_WxComboBox1, wxCB_READONLY);

relations->Add(AggregationType, 1);

multiplicityText = new wxStaticText(this, 0, wxS("multiplicity:"));
relations->Add(multiplicityText, 0, wxRIGHT|wxLEFT, 10);

Multiplicity = new wxComboBox(this, 0, wxEmptyString, wxDefaultPosition, wxDefaultSize, GetMultiplicityImplementations());
relations->Add(Multiplicity, 1);

topSizer->AddSpacer(10);

relations = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(relations, 0, wxEXPAND|wxRIGHT|wxLEFT, 10);

implementationText = new wxStaticText(this, 0, wxS("implement as:"));
relations->Add(implementationText, 0, wxRIGHT|wxLEFT, 10);

Implementation = new wxComboBox(this, ID_IMPLEMENTATION, wxEmptyString, wxDefaultPosition, wxDefaultSize, GetRelationImplementations());
relations->Add(Implementation, 1);

StaticField = new wxCheckBox(this, ID_STATIC, wxS("static"));
relations->Add(StaticField, 0, wxLEFT, 10);
StaticField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Static")) == wxS("yes"));

AggregationType->SetValue(wxConfigBase::Get()->Read(wxS("Astade/RelationType"), wxEmptyString));
Multiplicity->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Multiplicity"), wxEmptyString));
Implementation->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Implementation"), wxEmptyString));
