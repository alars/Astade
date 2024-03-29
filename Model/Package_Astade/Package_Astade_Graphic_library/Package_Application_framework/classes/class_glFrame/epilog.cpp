BEGIN_EVENT_TABLE(glFrame,glGeneratedFrame)
	EVT_CLOSE(glFrame::OnExit)
	EVT_MENU(ID_About, glFrame::OnAbout)
	EVT_MENU(ID_OPEN, glFrame::OnOpen)
	EVT_MENU(ID_SAVEAS, glFrame::OnSaveAs)
	EVT_MENU(ID_SAVEASDRAWIO, glFrame::OnSaveAsDrawIo)
	EVT_MENU(ID_SAVE, glFrame::OnSave)
	EVT_MENU(ID_NEW, glFrame::OnNew)
	EVT_MENU(ID_COPYGRAPH, glFrame::CopyBitmap)
	EVT_MENU(ID_SAVEGRAPH, glFrame::SaveGraphic)
	EVT_MENU_RANGE(ID_FIT, ID_1920_1440, glFrame::OnSizeChange)
	EVT_COMMAND_SCROLL(ID_xPixelSlider, glFrame::OnSliderMove)
	EVT_COMMAND_SCROLL(ID_yPixelSlider, glFrame::OnSliderMove)
	EVT_RADIOBOX(ID_SpeedBox, glFrame::OnSpeedChange)
END_EVENT_TABLE()
