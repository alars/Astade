myMenuBar->GetMenu(0)->Append(ID_NEW,"New","", wxITEM_NORMAL);
myMenuBar->GetMenu(0)->Append(ID_OPEN,"Open","", wxITEM_NORMAL);
myMenuBar->GetMenu(0)->Append(ID_SAVE,"Save","", wxITEM_NORMAL);
myMenuBar->GetMenu(0)->AppendSeparator();
myMenuBar->GetMenu(0)->Append(ID_SAVEAS,"Save as ...","", wxITEM_NORMAL);
myMenuBar->GetMenu(0)->Append(ID_SAVEGRAPH,"Save graphic as ...","", wxITEM_NORMAL);
myMenuBar->GetMenu(0)->Append(ID_COPYGRAPH,"Copy graphic to clipboard","", wxITEM_NORMAL);

myMenuBar->GetMenu(1)->Append(ID_FIT,"fit in window","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_240_180,"240 x 180","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_320_240,"320 x 240","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_640_480,"640 x 480","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_800_600,"800 x 600","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_1024_768,"1024 x 768","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_1200_900,"1200 x 900","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_1400_1050,"1400 x 1050","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_1600_1200,"1600 x 1200","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_1920_1440,"1920 x 1440","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_2800_2100,"2800 x 2100","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_3200_2400,"3200 x 2400","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_4096_3072,"4096 x 3072","", wxITEM_NORMAL);
myMenuBar->GetMenu(1)->Append(ID_6400_4800,"6400 x 4800","", wxITEM_NORMAL);

graphicPanel->SetScrollRate(10, 10);

wxScrollEvent dummy;
OnSliderMove(dummy);