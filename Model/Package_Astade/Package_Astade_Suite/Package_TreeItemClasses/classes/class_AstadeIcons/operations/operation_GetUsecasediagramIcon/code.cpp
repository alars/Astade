#include "usecasediagram_png.h"

wxMemoryInputStream istream(usecasediagram_png, sizeof usecasediagram_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);