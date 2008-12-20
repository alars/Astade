#include "found_png.h"

wxMemoryInputStream istream(found_png, sizeof found_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);