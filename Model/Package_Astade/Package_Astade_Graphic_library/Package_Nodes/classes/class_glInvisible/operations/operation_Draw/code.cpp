//~~ void Draw(wxDC& dc) [glInvisible] ~~

if (isMouseOver())
{
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"), 1, wxSOLID));
    dc.SetBrush(wxTheColourDatabase->Find("RED"));
    dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), 6);
}
else
{
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLACK"), 1, wxSOLID));
    dc.SetBrush(wxTheColourDatabase->Find("BLACK"));
    dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), my_Radius);
}
