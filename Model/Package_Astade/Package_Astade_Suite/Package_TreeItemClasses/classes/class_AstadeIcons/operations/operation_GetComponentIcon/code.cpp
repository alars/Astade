#include "component_png.h"

wxMemoryInputStream istream(component_png, sizeof component_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);