#include "attribute_png.h"

wxMemoryInputStream istream(attribute_png, sizeof attribute_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);