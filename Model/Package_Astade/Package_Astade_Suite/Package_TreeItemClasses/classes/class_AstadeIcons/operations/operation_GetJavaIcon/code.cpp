//~~ wxBitmap GetJavaIcon() [AstadeIcons] ~~
#include "java_png.h"

wxMemoryInputStream istream(java_png, sizeof java_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);