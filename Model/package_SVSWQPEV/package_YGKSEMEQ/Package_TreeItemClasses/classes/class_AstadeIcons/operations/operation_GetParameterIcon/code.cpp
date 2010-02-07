#include "parameter_png.h"

wxMemoryInputStream istream(parameter_png, sizeof parameter_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);