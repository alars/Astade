#include "inouparameter_png.h"

wxMemoryInputStream istream(inouparameter_png, sizeof inouparameter_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);