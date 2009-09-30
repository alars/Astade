if (isMouseOver())
{
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
  dc.SetBrush(wxTheColourDatabase->Find("WHITE"));
}
else
{
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("MAGENTA"),1,wxSOLID));
  dc.SetBrush(wxTheColourDatabase->Find("WHITE"));
}

dc.DrawCircle(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord(),my_Radius);

if (isMouseOver())
  dc.SetBrush(wxTheColourDatabase->Find("RED"));
else
  dc.SetBrush(wxTheColourDatabase->Find("MAGENTA"));

dc.DrawCircle(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord(),my_Radius/2);
