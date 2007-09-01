#include "relation_png.h"

wxMemoryInputStream istream(relation_png, sizeof relation_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);