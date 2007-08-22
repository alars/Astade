wxIcon aIcon;
aIcon.CopyFromBitmap(wxBitmap(wxImage(wxBitmap(XPM_Data).ConvertToImage()).Rescale(ASTADEICONSIZE,ASTADEICONSIZE)));
return aIcon;