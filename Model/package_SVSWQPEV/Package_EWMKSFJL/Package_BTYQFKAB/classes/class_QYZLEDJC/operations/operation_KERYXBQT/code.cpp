if (myEdges.empty())
{
    if (isMouseOver())
	    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
    else
	    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),1,wxSOLID));
    dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("YELLOW")));
}
else
{
    if (isMouseOver())
	    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
    else
	    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("DARK GREY"),1,wxSOLID));
    dc.SetBrush(*wxWHITE);
}

dc.DrawCircle(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord(),my_Radius);
