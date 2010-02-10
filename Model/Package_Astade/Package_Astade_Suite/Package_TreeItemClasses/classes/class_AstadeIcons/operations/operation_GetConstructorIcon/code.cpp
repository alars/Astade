#include "constructor_png.h"

wxMemoryInputStream istream(constructor_png, sizeof constructor_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);