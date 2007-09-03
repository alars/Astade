#include "internaltransition_png.h"

wxMemoryInputStream istream(internaltransition_png, sizeof internaltransition_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);