#include "virtual_png.h"

wxMemoryInputStream istream(virtual_png, sizeof virtual_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);