#include "transition_png.h"

wxMemoryInputStream istream(transition_png, sizeof transition_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);