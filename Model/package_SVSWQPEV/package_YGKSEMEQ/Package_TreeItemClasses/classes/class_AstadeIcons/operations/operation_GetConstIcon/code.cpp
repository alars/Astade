#include "const_png.h"

wxMemoryInputStream istream(const_png, sizeof const_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);