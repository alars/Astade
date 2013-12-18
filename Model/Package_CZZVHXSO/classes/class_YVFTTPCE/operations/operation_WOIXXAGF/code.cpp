//~~ wxString optimizedString(wxString& string) [CMain] ~~
wxString ret;
while (string.size()>0)
{
    if (ret.size() > 0)
        ret += wxS("\\n");
    ret += cutSubstring(string, 20);
}
return ret;