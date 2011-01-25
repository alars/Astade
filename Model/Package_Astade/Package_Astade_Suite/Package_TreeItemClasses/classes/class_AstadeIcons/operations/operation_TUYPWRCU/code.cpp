//~~ wxBitmap GetDiagramIcon() [AstadeIcons] ~~
#include "diagram_png.h"

wxMemoryInputStream istream(diagram_png, sizeof diagram_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);