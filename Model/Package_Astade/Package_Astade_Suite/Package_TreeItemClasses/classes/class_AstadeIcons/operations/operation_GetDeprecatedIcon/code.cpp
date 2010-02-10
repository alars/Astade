#include "deprecated_png.h"

wxMemoryInputStream istream(deprecated_png, sizeof deprecated_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);