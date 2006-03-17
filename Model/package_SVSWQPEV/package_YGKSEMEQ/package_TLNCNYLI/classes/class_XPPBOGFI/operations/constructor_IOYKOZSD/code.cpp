wxFlexGridSizer *topsizer = new wxFlexGridSizer(3);
topsizer->AddGrowableCol(1);

wxBoxSizer* aSizer = new wxBoxSizer(wxVERTICAL);
SetSizer(aSizer);

aSizer->AddStretchSpacer();
aSizer->Add(topsizer, 0, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 10);

AddBrowseLine(topsizer,"Help file",helpPathTextControl,IDHELPPATHBROWSE);
AddBrowseLine(topsizer,"Feature editor",featureEditPathTextControl,IDFEATUREEDITPATHBROWSE);
AddBrowseLine(topsizer,"Code editor",codeEditPathTextControl,IDCODEEDITPATHBROWSE);
AddBrowseLine(topsizer,"OMD viewer",omdPathTextControl,IDOMDPATHBROWSE);
AddBrowseLine(topsizer,"Statechart viewer",statechartPathTextControl,IDSTATECHARTPATHBROWSE);
AddBrowseLine(topsizer,"Coder",coderPathTextControl,IDCODERPATHBROWSE);
AddBrowseLine(topsizer,"Statechart coder",statechartCoderPathTextControl,IDSTATECHARTCODERBROWSE);
AddBrowseLine(topsizer,"Sequences",sequencesPathTextControl,IDSEQUENCESBROWSE);
AddBrowseLine(topsizer,"Make",makePathTextControl,IDMAKEPATHBROWSE);
AddBrowseLine(topsizer,"Templates path",templatesPathTextControl,IDTEMPLATESPATHBROWSE);

//Buttons
wxBoxSizer* anotherSize = new wxBoxSizer(wxHORIZONTAL);
cancel = new wxButton(this, wxID_CANCEL);
anotherSize->Add(cancel, 0, wxLEFT, 10);
anotherSize->AddStretchSpacer();
anotherSize->Add(new wxButton(this, wxID_OK), 0, wxALIGN_RIGHT | wxRIGHT, 10);

aSizer->AddStretchSpacer();
aSizer->Add(anotherSize, 0, wxEXPAND);

aSizer->SetSizeHints(this);

int x, y;

GetSize(&x, &y);
SetSize(2*x, y);
