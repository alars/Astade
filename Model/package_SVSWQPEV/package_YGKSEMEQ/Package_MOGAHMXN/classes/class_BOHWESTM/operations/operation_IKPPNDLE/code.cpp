#include "destructor_png.h"

wxMemoryInputStream istream(destructor_png, sizeof destructor_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);