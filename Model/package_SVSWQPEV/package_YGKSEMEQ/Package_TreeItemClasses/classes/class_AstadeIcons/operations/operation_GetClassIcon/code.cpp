#include "class_png.h"

wxMemoryInputStream istream(class_png, sizeof class_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);