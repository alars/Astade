#include "traced_png.h"

wxMemoryInputStream istream(traced_png, sizeof traced_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);
