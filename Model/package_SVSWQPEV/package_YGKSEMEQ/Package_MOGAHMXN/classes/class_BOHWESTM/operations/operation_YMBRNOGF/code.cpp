#include "run_png.h"

wxMemoryInputStream istream(run_png, sizeof run_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);