//~~ wxString GetName() [AdeConnection] ~~

wxString name(GetOutputObject());
if (!GetOutputPort().empty())
    name += wxS("_") + GetOutputPort();
return name;
