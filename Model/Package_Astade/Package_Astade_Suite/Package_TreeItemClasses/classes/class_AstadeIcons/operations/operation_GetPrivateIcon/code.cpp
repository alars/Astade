#include "private_png.h"

wxMemoryInputStream istream(private_png, sizeof private_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);