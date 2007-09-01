#include "composition_png.h"

wxMemoryInputStream istream(composition_png, sizeof composition_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);