//~~ void Init() [glFrame] ~~

myMenuBar->GetMenu(0)->Append(ID_NEW, wxS("New"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(0)->Append(ID_OPEN, wxS("Open"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(0)->Append(ID_SAVE, wxS("Save"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(0)->AppendSeparator();
myMenuBar->GetMenu(0)->Append(ID_SAVEAS, wxS("Save as ..."), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(0)->Append(ID_SAVEASDRAWIO, wxS("Export graphic as draw io"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(0)->Append(ID_SAVEGRAPH, wxS("Export graphic as ..."), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(0)->Append(ID_COPYGRAPH, wxS("Copy graphic to clipboard"), wxEmptyString, wxITEM_NORMAL);

myMenuBar->GetMenu(1)->Append(ID_FIT, wxS("fit in window"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_240_180, wxS("240 x 180"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_320_240, wxS("320 x 240"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_640_480, wxS("640 x 480"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_800_600, wxS("800 x 600"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_1024_768, wxS("1024 x 768"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_1200_900, wxS("1200 x 900"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_1400_1050, wxS("1400 x 1050"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_1600_1200, wxS("1600 x 1200"), wxEmptyString, wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_1920_1440, wxS("1920 x 1440"), wxEmptyString, wxITEM_NORMAL);

myMenuBar->GetMenu(2)->Append(ID_About, wxS("about"), wxEmptyString, wxITEM_NORMAL);

int w,h;
graphicPanel->GetSize(&w,&h);
graphicPanel->SetVirtualSize(2, 2); //No scroll bars please
xPixelSlider->SetValue(w);
yPixelSlider->SetValue(h);

wxScrollEvent dummy;
OnSliderMove(dummy);

wxImage::AddHandler(new wxPNGHandler);
wxImage::AddHandler(new wxJPEGHandler);
