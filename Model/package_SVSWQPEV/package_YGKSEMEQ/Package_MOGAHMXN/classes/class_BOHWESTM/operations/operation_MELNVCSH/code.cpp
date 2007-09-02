#include "sequence_png.h"

wxMemoryInputStream istream(sequence_png, sizeof sequence_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);