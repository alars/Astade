#include "selftransition_png.h"

wxMemoryInputStream istream(selftransition_png, sizeof selftransition_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);