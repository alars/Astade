#include "inline_png.h"

wxMemoryInputStream istream(inline_png, sizeof inline_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);