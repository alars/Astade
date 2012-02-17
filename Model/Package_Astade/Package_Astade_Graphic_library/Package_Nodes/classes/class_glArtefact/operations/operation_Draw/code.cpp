//~~ void Draw(wxDC& dc) [glArtefact] ~~

const int middleBorder = 4;
const int secondBorder = 16;

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
	dc.SetPen(*wxLIGHT_GREY_PEN);

dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(wxS("CornflowerBlue"))));

wxPoint pointlist[5];

pointlist[0] = wxPoint(absGetDrawPosition().xCoord() - my_XRadius, absGetDrawPosition().yCoord() - my_YRadius);
pointlist[1] = wxPoint(absGetDrawPosition().xCoord() + my_XRadius - 15, absGetDrawPosition().yCoord() - my_YRadius);
pointlist[2] = wxPoint(absGetDrawPosition().xCoord() + my_XRadius, absGetDrawPosition().yCoord() - my_YRadius + 15);
pointlist[3] = wxPoint(absGetDrawPosition().xCoord() + my_XRadius, absGetDrawPosition().yCoord() + my_YRadius);
pointlist[4] = wxPoint(absGetDrawPosition().xCoord() - my_XRadius, absGetDrawPosition().yCoord() + my_YRadius);

dc.DrawPolygon(5, pointlist);

pointlist[0] = wxPoint(absGetDrawPosition().xCoord() + my_XRadius - 15, absGetDrawPosition().yCoord() - my_YRadius);
pointlist[1] = wxPoint(absGetDrawPosition().xCoord() + my_XRadius, absGetDrawPosition().yCoord() - my_YRadius + 15);
pointlist[2] = wxPoint(absGetDrawPosition().xCoord() + my_XRadius - 15, absGetDrawPosition().yCoord() - my_YRadius + 15);

dc.SetBrush(*wxLIGHT_GREY);

dc.DrawPolygon(3,pointlist);

wxCoord x,y = 0;
dc.GetTextExtent(myLabel,&x,&y);

// Fits in one line?
if (x < (2 * my_XRadius) - middleBorder)
{
	dc.DrawText(myLabel, absGetDrawPosition().m_x - (x/2), absGetDrawPosition().m_y - (y/2));
	if (static_cast<glNoteGravityArea*>(myGravityArea)->GetHeight() > 46)
	{
		Refresh();
 		static_cast<glNoteGravityArea*>(myGravityArea)->SetHeight(46);
 		my_YRadius = 23;
	}
	return;
}

// Fits in two lines?
wxString secondPart = myLabel;
wxString firstPart = cutSubstring(secondPart, dc, (2 * my_XRadius) - middleBorder);
dc.GetTextExtent(firstPart, &x, &y);

wxCoord x2,y2;
dc.GetTextExtent(secondPart, &x2, &y2);

if (x2 < (2 * my_XRadius) - middleBorder)
{
	dc.DrawText(firstPart,absGetDrawPosition().m_x - my_XRadius + (middleBorder/2), absGetDrawPosition().m_y - (y/2));
	dc.DrawText(secondPart,absGetDrawPosition().m_x - my_XRadius + (middleBorder/2), absGetDrawPosition().m_y + (y/2));
	if (static_cast<glNoteGravityArea*>(myGravityArea)->GetHeight() > 46)
	{
		Refresh();
		static_cast<glNoteGravityArea*>(myGravityArea)->SetHeight(46);
		my_YRadius = 23;
	}
 	return;
}

// MultiLines

std::list<wxString> stringlist;
wxString label(myLabel);

stringlist.push_back(cutSubstring(label, dc, (2 * my_XRadius) - secondBorder));

while (label.Len() > 0)
{
	stringlist.push_back(cutSubstring(label, dc, (2 * my_XRadius) - middleBorder));
}

int i = 0;

for (std::list<wxString>::iterator it = stringlist.begin(); it != stringlist.end(); ++it)
{
	int ypos = absGetDrawPosition().m_y - (1.0 * y * ((1.0 * stringlist.size() / 2) - i));
	dc.DrawText(*it,absGetDrawPosition().m_x - my_XRadius + (middleBorder/2), ypos);
	i++;
}

if (i < 3) 
	i = 3;

if (static_cast<glNoteGravityArea*>(myGravityArea)->GetHeight() - 1 > (46 + (i - 3)*y))
{
	Refresh();
	my_YRadius = 46 + (i - 3) * y;
	my_YRadius /= 2;
	static_cast<glNoteGravityArea*>(myGravityArea)->SetHeight(2 * my_YRadius);
}

if (static_cast<glNoteGravityArea*>(myGravityArea)->GetHeight() + 1 < (46 + (i - 3) * y))
{
	my_YRadius = 46 + (i - 3)*y;
	my_YRadius /= 2;
	static_cast<glNoteGravityArea*>(myGravityArea)->SetHeight(2 * my_YRadius);
	Refresh();
}
