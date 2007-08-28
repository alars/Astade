#include "package_png.h"

wxMemoryInputStream istream(package_png, sizeof package_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);