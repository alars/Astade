#include "c_png.h"

wxMemoryInputStream istream(c_png, sizeof c_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);