#include "make_png.h"

wxMemoryInputStream istream(make_png, sizeof make_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);