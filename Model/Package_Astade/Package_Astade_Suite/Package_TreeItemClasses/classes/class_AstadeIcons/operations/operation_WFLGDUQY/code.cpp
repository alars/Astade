//~~ wxBitmap GetPythonIcon() [AstadeIcons] ~~
#include "python_png.h"

wxMemoryInputStream istream(python_png, sizeof python_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);