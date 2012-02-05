//~~ wxString GetLabel() [AdeConnection] ~~

wxString from(GetOutputObject());
wxString to(GetInputObject());

if (!GetOutputPort().empty())
    from = from + wxS(".") + GetOutputPort();

if (!GetInputPort().empty())
    to = to + wxS(".") + GetInputPort();

return from + wxS(" -> ") + to;
