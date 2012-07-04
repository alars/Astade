//~~ bool OnInit() [StaircaseApp] ~~

StaircaseFrame *myFrame = new  StaircaseFrame(0, -1, wxS("Staircase Light"));
SetTopWindow(myFrame);
myFrame->Init();

return true;
