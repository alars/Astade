//~~ AdeModelElement(const wxFileName& theFileName) [AdeModelElement] ~~
myFileName.Assign(theFileName);
myFileName.MakeAbsolute();
Reload();