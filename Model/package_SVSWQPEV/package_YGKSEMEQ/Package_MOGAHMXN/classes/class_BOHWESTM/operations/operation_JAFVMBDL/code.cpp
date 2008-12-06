// if yes, we have to remove the exiting one first
//Remove(name);

// wxImageList under MSW cannot handle alpha channel,
// this work around sets a solid white background
//#ifdef WXMSW
	wxBitmap newBitmap(ASTADEICONWIDTH, ASTADEICONHIGHT);
	wxMemoryDC dc(newBitmap);
	dc.SetBackground(*wxWHITE_BRUSH);
	dc.Clear();
	dc.DrawBitmap(bitmap, 0, 0, true);
	int index = Add(wxBitmap(newBitmap.ConvertToImage()), wxNullBitmap);
//#else
//	int index = Add(bitmap, wxNullBitmap);
//#endif

myIconNameMap[name] = index;
myIconBitmapMap[index] = bitmap;

return index;