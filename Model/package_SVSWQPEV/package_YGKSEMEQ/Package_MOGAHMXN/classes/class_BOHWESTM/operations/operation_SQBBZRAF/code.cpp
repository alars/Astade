#include "protected_png.h"

wxMemoryInputStream istream(protected_png, sizeof protected_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);