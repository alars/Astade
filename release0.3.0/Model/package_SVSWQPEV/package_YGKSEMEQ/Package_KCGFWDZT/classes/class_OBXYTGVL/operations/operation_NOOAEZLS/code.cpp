myDlg = new(ResourceEdit);

wxFileConfig* theConfig = new wxFileConfig(wxEmptyString,wxEmptyString,wxGetApp().argv[1]);
wxConfigBase::Set(theConfig);

SetTopWindow(myDlg);
myDlg->Show(TRUE);

return TRUE;
