#include "doxygen_png.h"

wxMemoryInputStream istream(doxygen_png, sizeof doxygen_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);