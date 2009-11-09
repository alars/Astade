//#include "splash_png.h"
wxInitAllImageHandlers();

//wxMemoryInputStream istream(splash_png, sizeof splash_png);
//wxImage myimage(istream, wxBITMAP_TYPE_PNG);

//wxSplashScreen splash(wxBitmap(myimage),
//          wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
//          20000, NULL, -1, wxDefaultPosition, wxDefaultSize,
//          wxSIMPLE_BORDER|wxSTAY_ON_TOP);

wxConfigBase::Set(new wxFileConfig("Astade.ini"));

InitializeFrame();

return true;
