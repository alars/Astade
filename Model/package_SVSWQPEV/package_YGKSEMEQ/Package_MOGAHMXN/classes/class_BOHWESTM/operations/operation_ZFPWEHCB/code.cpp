wxIcon aIcon;
aIcon.CopyFromBitmap(wxBitmap(wxImage(wxBitmap(XPM_Data).ConvertToImage()).Rescale(ASTADEICONWIDTH,ASTADEICONHIGHT)));
return aIcon;