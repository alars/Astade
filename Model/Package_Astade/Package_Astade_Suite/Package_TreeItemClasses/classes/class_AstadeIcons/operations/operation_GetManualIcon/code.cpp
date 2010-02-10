#include "manual_png.h"

wxMemoryInputStream istream(manual_png, sizeof manual_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);