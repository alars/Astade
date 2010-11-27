//~~ void AddButtonSizer(wxSizer* topSizer, bool hasTracelevel = false, bool hasLanguageSelection = false, bool hasNamespaceSelection = false) [ResourceEdit] ~~

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
	//wxString choices[] = {CODE_CPlusPlus, CODE_C, CODE_JAVA, CODE_PYTHON, CODE_PHP};
    //codingLanguage = new wxComboBox(this, ID_CCODED, wxEmptyString, wxDefaultPosition, wxDefaultSize, 5, choices, wxCB_READONLY);
	wxString choices[] = {CODE_CPlusPlus, CODE_C};
    codingLanguage = new wxComboBox(this, ID_CCODED, wxEmptyString, wxDefaultPosition, wxDefaultSize, 2, choices, wxCB_READONLY);
	button_sizer->Add(codingLanguage, 0);
    
    wxString language;
	if (!wxConfigBase::Get()->Read("Astade/CodingLanguage", &language))
		language = wxConfigBase::Get()->Read("Astade/CCoded") == "yes" ? CODE_C : CODE_CPlusPlus;
	if (language == "Ansi C")
		language = CODE_C;
    codingLanguage->SetValue(language);
}

if (hasNamespaceSelection)
{
    isNamespace = new wxCheckBox(this, ID_NAMESPACE, "code as namespace");
    isNamespace->SetValue(wxConfigBase::Get()->Read("Astade/IsNamespace","no") == "yes");
	button_sizer->Add(isNamespace, 0);
 }

button_sizer->AddStretchSpacer();

button_sizer->Add(new wxButton(this, wxID_CANCEL), 0);

button_sizer->AddSpacer(10);

button_sizer->Add(new wxButton(this, wxID_OK), 0, wxALIGN_RIGHT);
