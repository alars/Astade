#include "abstract_png.h"

wxMemoryInputStream istream(abstract_png, sizeof abstract_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);