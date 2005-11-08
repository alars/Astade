SetMinSize(wxSize(380,300));
wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );
SetSizer( topsizer );

topsizer->AddStretchSpacer();

AddBrowseLine(topsizer,"Model path",modelPathTextControl,IDMODELPATHBROWSE);
AddBrowseLine(topsizer,"Help file",helpPathTextControl,IDHELPPATHBROWSE);
AddBrowseLine(topsizer,"Feature editor",featureEditPathTextControl,IDFEATUREEDITPATHBROWSE);
AddBrowseLine(topsizer,"Code editor",codeEditPathTextControl,IDCODEEDITPATHBROWSE);
AddBrowseLine(topsizer,"OMD viewer",omdPathTextControl,IDOMDPATHBROWSE);
AddBrowseLine(topsizer,"Coder",coderPathTextControl,IDCODERPATHBROWSE);
AddBrowseLine(topsizer,"Make",makePathTextControl,IDMAKEPATHBROWSE);
AddBrowseLine(topsizer,"Templates path",templatesPathTextControl,IDTEMPLATESPATHBROWSE);

//Buttons
topsizer->AddStretchSpacer();

wxBoxSizer *button_sizer = new wxBoxSizer( wxHORIZONTAL );
topsizer->Add(button_sizer,0,wxEXPAND|wxALL|wxALIGN_BOTTOM,10);

button_sizer->Add(
	new wxButton(this, wxID_CANCEL, "cancel"),0);

button_sizer->AddStretchSpacer();

button_sizer->Add(
	new wxButton(this, IDSAVEEXIT, "Save and Exit"),0,wxALIGN_RIGHT);
