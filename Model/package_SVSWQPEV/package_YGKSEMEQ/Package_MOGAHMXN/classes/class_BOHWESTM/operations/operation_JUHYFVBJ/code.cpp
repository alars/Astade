#include "inparameter_png.h"

wxMemoryInputStream istream(inparameter_png, sizeof inparameter_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);