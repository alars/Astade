wxBoxSizer *relations = new wxBoxSizer( wxHORIZONTAL );
topSizer->Add(relations,0,wxEXPAND|wxRIGHT|wxLEFT,10);

wxArrayString arrayStringFor_WxComboBox1;
arrayStringFor_WxComboBox1.Add("ImplementationDependency");
arrayStringFor_WxComboBox1.Add("SpecificationDependency");
arrayStringFor_WxComboBox1.Add("Association");
arrayStringFor_WxComboBox1.Add("Aggregation");
arrayStringFor_WxComboBox1.Add("Composition");
arrayStringFor_WxComboBox1.Add("Generalization");

AggregationType =  new wxComboBox(this, ID_AGREGATIONTYPE ,wxEmptyString ,wxDefaultPosition,wxDefaultSize, arrayStringFor_WxComboBox1, wxCB_READONLY   );

relations->Add(AggregationType,1);

multiplicityText = new wxStaticText(this, 0 ,"multiplicity:");
relations->Add(multiplicityText,0,wxRIGHT|wxLEFT,10);

Multiplicity =  new wxComboBox(this, 0, wxEmptyString, wxDefaultPosition, wxDefaultSize, GetMultiplicityImplementations());
relations->Add(Multiplicity,1);

relations = new wxBoxSizer( wxHORIZONTAL );
topSizer->Add(relations,0,wxEXPAND|wxRIGHT|wxLEFT,10);

implementationText = new wxStaticText(this, 0 ,"implement as:");
relations->Add(implementationText,0,wxRIGHT|wxLEFT,10);

Implementation =  new wxComboBox(this, ID_IMPLEMENTATION, wxEmptyString, wxDefaultPosition, wxDefaultSize, GetRelationImplementations());
relations->Add(Implementation,1);

AggregationType->SetValue(wxConfigBase::Get()->Read("Astade/RelationType",wxEmptyString));
Multiplicity->SetValue(wxConfigBase::Get()->Read("Astade/Multiplicity",wxEmptyString));
Implementation->SetValue(wxConfigBase::Get()->Read("Astade/Implementation",wxEmptyString));
