#include "file_png.h"

wxMemoryInputStream istream(file_png, sizeof file_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);