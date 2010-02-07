#include "h_png.h"

wxMemoryInputStream istream(h_png, sizeof h_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);