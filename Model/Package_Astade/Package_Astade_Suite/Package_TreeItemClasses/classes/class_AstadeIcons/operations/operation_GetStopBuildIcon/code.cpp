#include "stop_png.h"

wxMemoryInputStream istream(stop_png, sizeof stop_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);
