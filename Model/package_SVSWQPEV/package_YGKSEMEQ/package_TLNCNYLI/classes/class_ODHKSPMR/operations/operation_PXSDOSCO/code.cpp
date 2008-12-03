//keyboard shortcut
		int count = 16;
wxAcceleratorEntry entries[count];
entries[0].Set(wxACCEL_CTRL,  (int) 'C',     ID_COPY);
entries[1].Set(wxACCEL_CTRL,  (int) 'V',     ID_PASTE);
entries[2].Set(wxACCEL_CTRL, (int) 'X',     ID_CUT);
entries[3].Set(wxACCEL_NORMAL,  WXK_DELETE,  ID_DELETE);
entries[4].Set(wxACCEL_CTRL, (int) 'G', ID_REGENERATE);
entries[5].Set(wxACCEL_CTRL, (int) 'A', ID_ACTIVECONFIGURATION);

entries[9].Set(wxACCEL_ALT, (int) 'T', ID_ADDCOMPONENTFOLDER);
entries[10].Set(wxACCEL_ALT, (int) 'O', ID_ADDCOMPONENT);
entries[11].Set(wxACCEL_ALT,(int) 'K', ID_ADDPACKAGE);
entries[12].Set(wxACCEL_ALT, (int) 'S', ID_ADDCLASSES);
entries[13].Set(wxACCEL_ALT, (int) 'C', ID_ADDCLASS);
entries[14].Set(wxACCEL_ALT, (int) 'L', ID_ADDLIBCLASS);
entries[15].Set(wxACCEL_CTRL, (int) 'F', ID_FEATURES);
wxAcceleratorTable accel(count, entries);
this->SetAcceleratorTable(accel);
