#include "containundocumented_png.h"

wxMemoryInputStream istream(containundocumented_png, sizeof containundocumented_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);