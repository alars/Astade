//~~ AstadeDirDialog() [AstadeDirDialog] ~~

wxFlexGridSizer *topsizer = new wxFlexGridSizer(3);
topsizer->AddGrowableCol(1);

wxBoxSizer* aSizer = new wxBoxSizer(wxVERTICAL);
SetSizer(aSizer);

aSizer->AddStretchSpacer();
aSizer->Add(topsizer, 0, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 10);

AddBrowseLine(topsizer, wxS("Doxygen Wizard"), DoxWizTextControl,IDDOCWIZBROWSE);
AddBrowseLine(topsizer, wxS("Feature editor"), featureEditPathTextControl,IDFEATUREEDITPATHBROWSE);
AddBrowseLine(topsizer, wxS("Code editor"), codeEditPathTextControl,IDCODEEDITPATHBROWSE);

topsizer->Add(new wxStaticText(this, 0, wxS("Editor line option")), 0, wxRIGHT, 10);
editLineOption = new wxTextCtrl(this, 0, wxEmptyString);
topsizer->Add(editLineOption, 1, wxRIGHT | wxEXPAND, 10);
topsizer->AddStretchSpacer();

AddBrowseLine(topsizer, wxS("OMD viewer"), omdPathTextControl,IDOMDPATHBROWSE);
AddBrowseLine(topsizer, wxS("Statechart viewer"), statechartPathTextControl,IDSTATECHARTPATHBROWSE);
AddBrowseLine(topsizer, wxS("Composite structure viewer"), compositeStructurePathTextControl,IDCOMPOSITEPATHBROWSE);
AddBrowseLine(topsizer, wxS("C++ Coder"), coderPathTextControl,IDCODERPATHBROWSE);
AddBrowseLine(topsizer, wxS("C Coder"), ccoderPathTextControl,IDCCODERPATHBROWSE);
AddBrowseLine(topsizer, wxS("Python Coder"), pythoncoderPathTextControl,IDPYTHONCODERPATHBROWSE);
AddBrowseLine(topsizer, wxS("Statechart coder"), statechartCoderPathTextControl,IDSTATECHARTCODERBROWSE);
AddBrowseLine(topsizer, wxS("Sequences"), sequencesPathTextControl,IDSEQUENCESBROWSE);
AddBrowseLine(topsizer, wxS("UseCaseEdit"), usecasePathTextControl,IDUSECASEEDIT);
AddBrowseLine(topsizer, wxS("Make"), makePathTextControl,IDMAKEPATHBROWSE);
AddBrowseLine(topsizer, wxS("Sound after Make"), soundPathTextControl,IDSOUNDPATHBROWSE);
AddBrowseLine(topsizer, wxS("Templates path"), templatesPathTextControl,IDTEMPLATESPATHBROWSE);

//Buttons
wxBoxSizer* anotherSize = new wxBoxSizer(wxHORIZONTAL);
anotherSize->Add(new wxButton(this, ID_DEFAULT, wxS("Restore Defaults")), 0, wxALIGN_LEFT | wxLEFT | wxRIGHT, 10);
anotherSize->AddStretchSpacer();
cancel = new wxButton(this, wxID_CANCEL);
anotherSize->Add(cancel, 0, wxRIGHT, 10);
anotherSize->Add(new wxButton(this, wxID_OK), 0, wxALIGN_RIGHT | wxRIGHT, 10);

aSizer->AddStretchSpacer();
aSizer->Add(anotherSize, 0, wxEXPAND | wxBOTTOM, 10);

aSizer->SetSizeHints(this);

int x, y;
GetSize(&x, &y);
SetSize(2*x, 1.1*y);
