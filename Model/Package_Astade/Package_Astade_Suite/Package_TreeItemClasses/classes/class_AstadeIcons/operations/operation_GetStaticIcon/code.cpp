#include "static_png.h"

wxMemoryInputStream istream(static_png, sizeof static_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);