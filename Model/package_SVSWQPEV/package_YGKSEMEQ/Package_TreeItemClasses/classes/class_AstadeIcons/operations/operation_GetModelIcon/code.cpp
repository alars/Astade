#include "model_png.h"

wxMemoryInputStream istream(model_png, sizeof model_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);