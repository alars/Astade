//~~ void shrinkString(wxString& string, const wxDC& dc, int pixelCount) [glNode] ~~

wxCoord x, y;
dc.GetTextExtent(string, &x, &y);
if (x >= pixelCount)
{
    do
    {
        string.RemoveLast();
        dc.GetTextExtent(string + wxS("..."), &x, &y);
    } while(x >= pixelCount);
    string += wxS("...");
}
