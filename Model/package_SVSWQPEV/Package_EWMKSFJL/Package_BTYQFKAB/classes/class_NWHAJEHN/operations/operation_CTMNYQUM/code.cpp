if (isMouseOver())
{
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
  dc.SetBrush(wxTheColourDatabase->Find("RED"));
}
else
{
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("MAGENTA"),1,wxSOLID));
  dc.SetBrush(wxTheColourDatabase->Find("MAGENTA"));
}

dc.DrawCircle(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord(),my_Radius);
