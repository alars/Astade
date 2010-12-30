//~~ wxString GetLabel() [AdeConnection] ~~
wxString from(GetOutputObject());
wxString to(GetInputObject());

if (!GetOutputPort().empty())
    from = from + "." + GetOutputPort();

if (!GetInputPort().empty())
    to = to + "." + GetInputPort();

return from + " -> " + to;
