//~~ wxString GetObject(const wxString& objectName, const wxString& portName) [AdeClass] ~~
wxString ret = GetObjectPort(objectName, portName);

if (!ret.empty())
{
    int dotpos = ret.Find('.', true);
    if (dotpos != wxNOT_FOUND)
        ret.Remove(dotpos);
}

return ret;