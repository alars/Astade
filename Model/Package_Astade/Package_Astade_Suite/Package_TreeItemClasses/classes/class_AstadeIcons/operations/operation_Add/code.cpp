//~~ int Add(const wxBitmap& bitmap) [AstadeIcons] ~~

wxString name;
name.Printf(wxS("icon%d"), GetImageCount());
return Add(name, bitmap);
