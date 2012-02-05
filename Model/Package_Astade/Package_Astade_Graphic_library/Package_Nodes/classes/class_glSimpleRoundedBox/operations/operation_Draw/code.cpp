//~~ void Draw(wxDC& dc) [glSimpleRoundedBox] ~~

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("DARK GREY")), 1, wxSOLID));

dc.SetBrush(*wxWHITE);

dc.DrawCircle(absGetDrawPosition().xCoord() - my_XRadius+my_edgeRadius, absGetDrawPosition().yCoord() - my_YRadius+my_edgeRadius, my_edgeRadius);
dc.DrawCircle(absGetDrawPosition().xCoord() + my_XRadius-my_edgeRadius, absGetDrawPosition().yCoord() - my_YRadius+my_edgeRadius, my_edgeRadius);
dc.DrawCircle(absGetDrawPosition().xCoord() - my_XRadius+my_edgeRadius, absGetDrawPosition().yCoord() + my_YRadius-my_edgeRadius, my_edgeRadius);
dc.DrawCircle(absGetDrawPosition().xCoord() + my_XRadius-my_edgeRadius, absGetDrawPosition().yCoord() + my_YRadius-my_edgeRadius, my_edgeRadius);

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("WHITE")), 2, wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("WHITE")), 1, wxSOLID));

dc.DrawRectangle(absGetDrawPosition().xCoord() - my_XRadius+my_edgeRadius, absGetDrawPosition().yCoord() - my_YRadius, 2 * (my_XRadius - my_edgeRadius), 2 * my_YRadius);
dc.DrawRectangle(absGetDrawPosition().xCoord() - my_XRadius, absGetDrawPosition().yCoord() - my_YRadius + my_edgeRadius, 2 * my_XRadius, 2 * (my_YRadius - my_edgeRadius));

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("DARK GREY")), 1, wxSOLID));

dc.DrawLine(absGetDrawPosition().xCoord() - my_XRadius+my_edgeRadius,
			absGetDrawPosition().yCoord() - my_YRadius,
			absGetDrawPosition().xCoord() + my_XRadius - my_edgeRadius,
			absGetDrawPosition().yCoord() - my_YRadius);
						
dc.DrawLine(absGetDrawPosition().xCoord() - my_XRadius + my_edgeRadius,
			absGetDrawPosition().yCoord() + my_YRadius,
			absGetDrawPosition().xCoord() + my_XRadius - my_edgeRadius,
			absGetDrawPosition().yCoord() + my_YRadius);
						
dc.DrawLine(absGetDrawPosition().xCoord() - my_XRadius,
			absGetDrawPosition().yCoord() - my_YRadius + my_edgeRadius,
			absGetDrawPosition().xCoord() - my_XRadius,
			absGetDrawPosition().yCoord() + my_YRadius - my_edgeRadius);
						
dc.DrawLine(absGetDrawPosition().xCoord() + my_XRadius,
			absGetDrawPosition().yCoord() - my_YRadius + my_edgeRadius,
			absGetDrawPosition().xCoord() + my_XRadius,
			absGetDrawPosition().yCoord() + my_YRadius - my_edgeRadius);
