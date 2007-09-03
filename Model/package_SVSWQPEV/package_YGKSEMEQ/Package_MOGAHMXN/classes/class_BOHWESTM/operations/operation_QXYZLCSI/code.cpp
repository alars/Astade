#include "state_png.h"

wxMemoryInputStream istream(state_png, sizeof state_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);