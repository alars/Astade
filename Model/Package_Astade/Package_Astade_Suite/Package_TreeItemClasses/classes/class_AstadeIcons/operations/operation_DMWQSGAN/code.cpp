#include "framework_png.h"

wxMemoryInputStream istream(framework_png, sizeof framework_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);
