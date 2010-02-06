myStaticBitmap = new wxStaticBitmap(this,-1,OffBitmap,wxPoint(10,10),wxSize(100,100));
myButton = new wxButton(this,ID_LIGHTSWITCH,"switch",wxPoint(120,55));
wxCommandEvent aDummyEvent(0);
Initialize(aDummyEvent);
Show();