#include "website_png.h"

wxMemoryInputStream istream(website_png, sizeof website_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);