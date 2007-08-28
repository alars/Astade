#include "folder_png.h"

wxMemoryInputStream istream(folder_png, sizeof folder_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);