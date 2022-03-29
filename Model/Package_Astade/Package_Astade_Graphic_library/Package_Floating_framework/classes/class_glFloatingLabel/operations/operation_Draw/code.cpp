//~~ void Draw(wxDC& dc) [glFloatingLabel] ~~
wxCoord x,y;
dc.GetTextExtent(myText,&x,&y);
if ((my_hight != y) || (my_width != x))
{
    Refresh();
    my_hight = y;
    my_width = x;
}
dc.DrawText(myText,absGetDrawPosition().m_x-(x/2),absGetDrawPosition().m_y-(y/2));
