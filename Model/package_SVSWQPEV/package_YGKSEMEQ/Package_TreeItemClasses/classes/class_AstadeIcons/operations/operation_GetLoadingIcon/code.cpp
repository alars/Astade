#include "loading_png.h"

wxMemoryInputStream istream(loading_png, sizeof loading_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);