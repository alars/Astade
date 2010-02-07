#include "fastrun_png.h"

wxMemoryInputStream istream(fastrun_png, sizeof fastrun_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);