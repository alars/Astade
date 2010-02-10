#include "lib_png.h"

wxMemoryInputStream istream(lib_png, sizeof lib_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);