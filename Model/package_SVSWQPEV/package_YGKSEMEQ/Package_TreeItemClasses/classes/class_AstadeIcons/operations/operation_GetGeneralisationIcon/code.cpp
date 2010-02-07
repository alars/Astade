#include "generalisation_png.h"

wxMemoryInputStream istream(generalisation_png, sizeof generalisation_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);