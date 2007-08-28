#include "operation_png.h"

wxMemoryInputStream istream(operation_png, sizeof operation_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);