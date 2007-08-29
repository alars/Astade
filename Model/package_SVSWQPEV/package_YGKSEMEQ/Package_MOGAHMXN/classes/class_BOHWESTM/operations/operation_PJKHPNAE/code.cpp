#include "configuration_png.h"

wxMemoryInputStream istream(configuration_png, sizeof configuration_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);