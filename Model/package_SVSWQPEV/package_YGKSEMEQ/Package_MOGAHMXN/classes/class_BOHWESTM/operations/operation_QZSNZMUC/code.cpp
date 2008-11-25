#include "isundocumented_png.h"

wxMemoryInputStream istream(isundocumented_png, sizeof isundocumented_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);