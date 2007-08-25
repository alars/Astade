#include "public_png.h"

wxMemoryInputStream istream(public_png, sizeof public_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);