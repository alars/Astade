//keyboard shortcut
wxAcceleratorEntry entries[4];
  entries[0].Set(wxACCEL_CTRL,  (int) 'C',     ID_COPY);
  entries[1].Set(wxACCEL_CTRL,  (int) 'V',     ID_PASTE);
  entries[2].Set(wxACCEL_CTRL, (int) 'X',     ID_CUT);
  entries[3].Set(wxACCEL_NORMAL,  WXK_DELETE,  ID_DELETE);
  wxAcceleratorTable accel(4, entries);
  this->SetAcceleratorTable(accel);