#include "launchbuild_png.h"

wxMemoryInputStream istream(launchbuild_png, sizeof launchbuild_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);