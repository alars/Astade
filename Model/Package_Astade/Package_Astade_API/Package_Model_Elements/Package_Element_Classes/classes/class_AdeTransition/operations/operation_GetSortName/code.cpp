//~~ wxString GetSortName() [AdeTransition] ~~
if (IsAllTransition())
{
    if (GetGuard().empty())
    {
        return wxS("d")+GetName();
    }
    else
    {
        return wxS("c")+GetName();
    }
}
else
{
    if (GetGuard().empty())
    {
        return wxS("b")+GetName();
    }
    else
    {
        return wxS("a")+GetName();
    }
}