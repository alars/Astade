#include "statechart_png.h"

wxMemoryInputStream istream(statechart_png, sizeof statechart_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);