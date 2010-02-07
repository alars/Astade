#include "attention_png.h"

wxMemoryInputStream istream(attention_png, sizeof attention_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);