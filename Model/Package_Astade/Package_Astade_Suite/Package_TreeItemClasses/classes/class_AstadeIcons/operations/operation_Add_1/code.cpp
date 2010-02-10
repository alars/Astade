// wxImageList under MSW cannot handle alpha channel,
// this work around sets a solid white background
wxBitmap newBitmap(ASTADEICONWIDTH, ASTADEICONHEIGHT);
wxMemoryDC dc(newBitmap);
dc.SetBackground(*wxWHITE_BRUSH);
dc.Clear();
dc.DrawBitmap(bitmap, 0, 0, true);
int index = Add(wxBitmap(newBitmap.ConvertToImage()), wxNullBitmap);

myIconNameMap[name] = index;
myIconBitmapMap[index] = bitmap;

return index;
