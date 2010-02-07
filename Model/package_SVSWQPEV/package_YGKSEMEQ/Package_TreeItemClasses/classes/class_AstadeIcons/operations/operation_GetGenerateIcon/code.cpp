#include "generate_png.h"

wxMemoryInputStream istream(generate_png, sizeof generate_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);