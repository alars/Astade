#include "type_png.h"

wxMemoryInputStream istream(type_png, sizeof type_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);