#include "belonging_png.h"

wxMemoryInputStream istream(belonging_png, sizeof belonging_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);