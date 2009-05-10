const int middleBorder = 4;

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxColor(0x40, 0x7a, 0x40),1,wxSOLID));

dc.SetBrush(*wxWHITE);

wxPoint pointlist[5];

pointlist[0] = wxPoint(absGetDrawPosition().xCoord()-my_XRadius, absGetDrawPosition().yCoord()-my_YRadius);
pointlist[1] = wxPoint(absGetDrawPosition().xCoord()+my_XRadius-15, absGetDrawPosition().yCoord()-my_YRadius);
pointlist[2] = wxPoint(absGetDrawPosition().xCoord()+my_XRadius, absGetDrawPosition().yCoord()-my_YRadius+15);
pointlist[3] = wxPoint(absGetDrawPosition().xCoord()+my_XRadius, absGetDrawPosition().yCoord()+my_YRadius);
pointlist[4] = wxPoint(absGetDrawPosition().xCoord()-my_XRadius, absGetDrawPosition().yCoord()+my_YRadius);

dc.DrawPolygon(5,pointlist);

pointlist[0] = wxPoint(absGetDrawPosition().xCoord()+my_XRadius-15, absGetDrawPosition().yCoord()-my_YRadius);
pointlist[1] = wxPoint(absGetDrawPosition().xCoord()+my_XRadius, absGetDrawPosition().yCoord()-my_YRadius+15);
pointlist[2] = wxPoint(absGetDrawPosition().xCoord()+my_XRadius-15, absGetDrawPosition().yCoord()-my_YRadius+15);

dc.SetBrush(*wxLIGHT_GREY);

dc.DrawPolygon(3,pointlist);

wxCoord x,y;
dc.GetTextExtent(myLabel,&x,&y);

// Fits in one line?
if (x < (2 * my_XRadius) - middleBorder)
{
    dc.DrawText(myLabel,absGetDrawPosition().m_x-(x/2),absGetDrawPosition().m_y - (y/2));
    return;
}

// Fits in two lines?
int first = 0;

do
{
    dc.GetTextExtent(myLabel.Mid(0,++first),&x,&y);
} while (x < (2 * my_XRadius) - middleBorder);

wxString firstPart = myLabel.Mid(0,--first);

if (firstPart.Find(' ',true) > (int)(firstPart.size()/2))
    first = firstPart.Find(' ',true);
else if (firstPart.Find('-',true) > (int)(firstPart.size()/2))
    first = firstPart.Find('-',true)+1;

firstPart = myLabel.Mid(0,first);
firstPart.Trim(true);
firstPart.Trim(false);
dc.GetTextExtent(firstPart,&x,&y);

wxString secondPart = myLabel.Mid(first);
secondPart.Trim(true);
secondPart.Trim(false);

wxCoord x2,y2;
dc.GetTextExtent(secondPart,&x2,&y2);

if (x2 >= (2 * my_XRadius) - middleBorder)
{
    do
    {
        secondPart.RemoveLast();
        dc.GetTextExtent(secondPart+"...",&x2,&y2);
    } while(x2 >= (2 * my_XRadius) - middleBorder);
    secondPart += "...";
}

dc.DrawText(firstPart,absGetDrawPosition().m_x-my_XRadius+(middleBorder/2),absGetDrawPosition().m_y - (y/2));
dc.DrawText(secondPart,absGetDrawPosition().m_x-my_XRadius+(middleBorder/2),absGetDrawPosition().m_y + (y/2));

