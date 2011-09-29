//~~ AdeModelElement(const wxString& theFileName) [AdeModelElement] ~~
myFileName.Assign(theFileName);
myFileName.MakeAbsolute();
Reload();