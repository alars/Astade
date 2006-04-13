wxFlexGridSizer *topsizer = new wxFlexGridSizer(3);
topsizer->AddGrowableCol(1);

wxBoxSizer* aSizer = new wxBoxSizer(wxVERTICAL);
SetSizer(aSizer);

aSizer->AddStretchSpacer();
aSizer->Add(topsizer, 0, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 10);

AddBrowseLine(topsizer,"Help file",helpPathTextControl,IDHELPPATHBROWSE);
AddBrowseLine(topsizer,"HTML Browser",htmlBrowserPathTextControl,IDHTMLBROWSERPATHBROWSE);
AddBrowseLine(topsizer,"Feature editor",featureEditPathTextControl,IDFEATUREEDITPATHBROWSE);
AddBrowseLine(topsizer,"Code editor",codeEditPathTextControl,IDCODEEDITPATHBROWSE);

topsizer->Add(new wxStaticText(this, 0, "Editor line option"), 0, wxRIGHT, 10);
editLineOption = new wxTextCtrl(this, 0, wxEmptyString);
topsizer->Add(editLineOption, 1, wxRIGHT | wxEXPAND, 10);
topsizer->AddStretchSpacer();

AddBrowseLine(topsizer,"OMD viewer",omdPathTextControl,IDOMDPATHBROWSE);
AddBrowseLine(topsizer,"Statechart viewer",statechartPathTextControl,IDSTATECHARTPATHBROWSE);
AddBrowseLine(topsizer,"Coder",coderPathTextControl,IDCODERPATHBROWSE);
AddBrowseLine(topsizer,"Statechart coder",statechartCoderPathTextControl,IDSTATECHARTCODERBROWSE);
AddBrowseLine(topsizer,"Sequences",sequencesPathTextControl,IDSEQUENCESBROWSE);
AddBrowseLine(topsizer,"Make",makePathTextControl,IDMAKEPATHBROWSE);
AddBrowseLine(topsizer,"Sound after Make",soundPathTextControl,IDSOUNDPATHBROWSE);
AddBrowseLine(topsizer,"Templates path",templatesPathTextControl,IDTEMPLATESPATHBROWSE);

//Buttons
wxBoxSizer* anotherSize = new wxBoxSizer(wxHORIZONTAL);
cancel = new wxButton(this, wxID_CANCEL);
anotherSize->AddStretchSpacer();
anotherSize->Add(cancel, 0, wxRIGHT, 10);
anotherSize->Add(new wxButton(this, wxID_OK), 0, wxALIGN_RIGHT | wxRIGHT, 10);

aSizer->AddStretchSpacer();
aSizer->Add(anotherSize, 0, wxEXPAND | wxBOTTOM, 10);

aSizer->SetSizeHints(this);

int x, y;
GetSize(&x, &y);
SetSize(2*x, y);
