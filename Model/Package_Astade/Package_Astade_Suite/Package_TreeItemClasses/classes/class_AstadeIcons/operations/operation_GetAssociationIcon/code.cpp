#include "association_png.h"

wxMemoryInputStream istream(association_png, sizeof association_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);