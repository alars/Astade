#include "constraint_png.h"

wxMemoryInputStream istream(constraint_png, sizeof constraint_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);
