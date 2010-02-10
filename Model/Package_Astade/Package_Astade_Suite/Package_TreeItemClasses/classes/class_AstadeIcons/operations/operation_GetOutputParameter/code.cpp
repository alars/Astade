#include "outparameter_png.h"

wxMemoryInputStream istream(outparameter_png, sizeof outparameter_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);