//~~ wxBitmap GetNamespaceIcon() [AstadeIcons] ~~
#include "namespace_png.h"

wxMemoryInputStream istream(namespace_png, sizeof namespace_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);