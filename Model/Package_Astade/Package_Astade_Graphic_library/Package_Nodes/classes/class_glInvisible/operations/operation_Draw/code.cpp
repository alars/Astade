//~~ void Draw(wxDC& dc) [glInvisible] ~~

if (isMouseOver())
{
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 1, wxSOLID));
    dc.SetBrush(wxTheColourDatabase->Find(wxS("RED")));
    dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), 6);
}
else
{
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLACK")), 1, wxSOLID));
    dc.SetBrush(wxTheColourDatabase->Find(wxS("BLACK")));
    dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), my_Radius);
}
