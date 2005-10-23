wxString t(wxGetApp().argv[1]);
myDlg.file = t;
SetTopWindow(&myDlg);
myDlg.Show(TRUE);
return TRUE;
