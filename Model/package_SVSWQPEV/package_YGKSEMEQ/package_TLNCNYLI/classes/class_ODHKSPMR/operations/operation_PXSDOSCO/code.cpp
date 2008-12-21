//keyboard shortcut
int count = 18;

wxAcceleratorEntry entries[count];
entries[0].Set(wxACCEL_CTRL,  (int) 'C',     ID_COPY);
entries[1].Set(wxACCEL_CTRL,  (int) 'V',     ID_PASTE);
entries[2].Set(wxACCEL_CTRL, (int) 'X',     ID_CUT);
entries[3].Set(wxACCEL_NORMAL,  WXK_DELETE,  ID_DELETE);
entries[4].Set(wxACCEL_CTRL, (int) 'G', ID_REGENERATE);
entries[5].Set(wxACCEL_CTRL, (int) 'A', ID_ACTIVECONFIGURATION);
entries[6].Set(wxACCEL_ALT, (int) 'T', ID_ADDCOMPONENTFOLDER);
entries[7].Set(wxACCEL_ALT, (int) 'O', ID_ADDCOMPONENT);
entries[8].Set(wxACCEL_ALT,(int) 'K', ID_ADDPACKAGE);
entries[9].Set(wxACCEL_ALT, (int) 'S', ID_ADDCLASSES);
entries[10].Set(wxACCEL_ALT, (int) 'C', ID_ADDCLASS);
entries[11].Set(wxACCEL_ALT, (int) 'L', ID_ADDLIBCLASS);
entries[12].Set(wxACCEL_CTRL, (int) 'F', ID_SEARCH);
entries[13].Set(wxACCEL_SHIFT, WXK_F5, ID_REGENERATE);
entries[13].Set(wxACCEL_NORMAL, WXK_F5, ID_TOOL_GENERATE);
entries[14].Set(wxACCEL_NORMAL, WXK_F6, ID_TOOL_BUILD);
entries[15].Set(wxACCEL_SHIFT, WXK_F6, ID_TOOL_FASTBUILD);
entries[16].Set(wxACCEL_NORMAL, WXK_F7, ID_TOOL_RUN);
entries[17].Set(wxACCEL_SHIFT, WXK_F7, ID_TOOL_FASTRUN);

wxAcceleratorTable accel(count, entries);
this->SetAcceleratorTable(accel);
