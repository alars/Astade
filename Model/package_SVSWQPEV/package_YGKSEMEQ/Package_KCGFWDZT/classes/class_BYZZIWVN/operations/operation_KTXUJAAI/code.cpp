wxBoxSizer *relations = new wxBoxSizer( wxHORIZONTAL );
topSizer->Add(relations,0,wxEXPAND|wxRIGHT|wxLEFT,10);

wxArrayString arrayStringFor_WxComboBox1;
arrayStringFor_WxComboBox1.Add("Normal");
arrayStringFor_WxComboBox1.Add("Internal");
arrayStringFor_WxComboBox1.Add("Self");

transitionType =  new wxComboBox(this, ID_AGREGATIONTYPE ,wxEmptyString ,wxDefaultPosition,wxDefaultSize, arrayStringFor_WxComboBox1, wxCB_READONLY   );

relations->Add(transitionType,1);

/*
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

*/
transitionType->SetValue(wxConfigBase::Get()->Read("Astade/TransitionType",wxEmptyString));

/*
Multiplicity->SetValue(wxConfigBase::Get()->Read("Astade/Multiplicity",wxEmptyString));
Implementation->SetValue(wxConfigBase::Get()->Read("Astade/Implementation",wxEmptyString));
*/