wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );
SetSizer( topsizer );

topsizer->AddSpacer(10);
topsizer->AddStretchSpacer();

AddBrowseLine(topsizer,"Model path",modelPathTextControl,IDMODELPATHBROWSE);
AddBrowseLine(topsizer,"Help file",helpPathTextControl,IDHELPPATHBROWSE);
AddBrowseLine(topsizer,"Feature editor",featureEditPathTextControl,IDFEATUREEDITPATHBROWSE);
AddBrowseLine(topsizer,"Code editor",codeEditPathTextControl,IDCODEEDITPATHBROWSE);
AddBrowseLine(topsizer,"OMD viewer",omdPathTextControl,IDOMDPATHBROWSE);
AddBrowseLine(topsizer,"Statechart viewer",statechartPathTextControl,IDSTATECHARTPATHBROWSE);
AddBrowseLine(topsizer,"Coder",coderPathTextControl,IDCODERPATHBROWSE);
AddBrowseLine(topsizer,"Statechart coder",statechartCoderPathTextControl,IDSTATECHARTCODERROWSE);
AddBrowseLine(topsizer,"Make",makePathTextControl,IDMAKEPATHBROWSE);
AddBrowseLine(topsizer,"Templates path",templatesPathTextControl,IDTEMPLATESPATHBROWSE);

//Buttons
topsizer->AddStretchSpacer();

wxBoxSizer *button_sizer = new wxBoxSizer( wxHORIZONTAL );
topsizer->Add(button_sizer,0,wxEXPAND|wxALL|wxALIGN_BOTTOM,10);

cancel = new wxButton(this, wxID_CANCEL, "cancel");
button_sizer->Add(cancel,0);

button_sizer->AddStretchSpacer();

button_sizer->Add(
	new wxButton(this, IDSAVEEXIT, "Save and Exit"),0,wxALIGN_RIGHT);

topsizer->SetSizeHints( this );

int x,y;

GetSize(&x,&y);
SetSize(2*x,y);