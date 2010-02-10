#include "agregation_png.h"

wxMemoryInputStream istream(agregation_png, sizeof agregation_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);