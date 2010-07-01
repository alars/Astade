//~~ void AddButtonSizer(wxSizer* topSizer, bool hasTracelevel = false, bool hasLanguageSelection = false) [ResourceEdit] ~~
wxBoxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(button_sizer, 0, wxEXPAND|wxALL|wxALIGN_BOTTOM, 10);

if (hasTracelevel)
{
	button_sizer->Add(new wxStaticText(this, 0, "Trace level:"), 0, wxRIGHT|wxLEFT, 10);
	traceLevel = new wxSpinCtrl(this);
	traceLevel->SetRange(0,9);
	button_sizer->Add(traceLevel, 0);
	traceLevel->SetValue(wxConfigBase::Get()->Read("Astade/Tracelevel",5));
}

if (hasLanguageSelection)
{
	wxString choices[] = {"C++", "Ansi C", "Java", "Python", "PHP"};
    codingLanguage = new wxComboBox(this, ID_CCODED, "", wxDefaultPosition, wxDefaultSize, 5, choices, wxCB_READONLY);
	button_sizer->Add(codingLanguage, 0);
    
    codingLanguage->SetValue(wxConfigBase::Get()->Read("Astade/CodingLanguage","C++"));
    if (wxConfigBase::Get()->Read("Astade/CCoded") == "yes")
        codingLanguage->SetValue("Ansi C");
}

button_sizer->AddStretchSpacer();

button_sizer->Add(new wxButton(this, wxID_CANCEL), 0);

button_sizer->AddSpacer(10);

button_sizer->Add(new wxButton(this, wxID_OK), 0, wxALIGN_RIGHT);
