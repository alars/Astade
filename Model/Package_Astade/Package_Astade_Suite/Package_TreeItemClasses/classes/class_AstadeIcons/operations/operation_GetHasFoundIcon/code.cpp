#include "hasfound_png.h"

wxMemoryInputStream istream(hasfound_png, sizeof hasfound_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);