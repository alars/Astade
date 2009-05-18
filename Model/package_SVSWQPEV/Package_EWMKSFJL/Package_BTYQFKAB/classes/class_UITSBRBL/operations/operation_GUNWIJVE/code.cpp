const int middleBorder = 4;
const int firstBorder = 10;
const int secondBorder = 24;

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("DARK GREY"),1,wxSOLID));

dc.SetBrush(*wxLIGHT_GREY);

dc.DrawEllipse(absGetDrawPosition().xCoord()-my_XRadius,absGetDrawPosition().yCoord()-my_YRadius,2*my_XRadius,2*my_YRadius);

wxCoord x,y;
dc.GetTextExtent(myLabel,&x,&y);

// Fits in one line?
if (x < (2 * my_XRadius) - middleBorder)
{
    dc.DrawText(myLabel,absGetDrawPosition().m_x-(x/2),absGetDrawPosition().m_y - (y/2));
    return;
}

// Fits in two lines?
wxString secondPart = myLabel;
wxString firstPart = cutSubstring(secondPart, dc, (2 * my_XRadius) - firstBorder);
dc.GetTextExtent(firstPart,&x,&y);

wxCoord x2,y2;
dc.GetTextExtent(secondPart,&x2,&y2);

if (x2 < (2 * my_XRadius) - firstBorder)
{
    dc.DrawText(firstPart,absGetDrawPosition().m_x-(x/2),absGetDrawPosition().m_y - y);
    dc.DrawText(secondPart,absGetDrawPosition().m_x-(x2/2),absGetDrawPosition().m_y);
    return;
}

// Fits in three lines?

wxString thirdPart = myLabel;
firstPart = cutSubstring(thirdPart, dc, (2 * my_XRadius) - secondBorder);
secondPart = cutSubstring(thirdPart, dc, (2 * my_XRadius) - middleBorder);

wxCoord x3,y3;
dc.GetTextExtent(firstPart,&x,&y);
dc.GetTextExtent(secondPart,&x2,&y2);
dc.GetTextExtent(thirdPart,&x3,&y3);


if (x3 >= (2 * my_XRadius) - secondBorder)
{
    do
    {
        thirdPart.RemoveLast();
        dc.GetTextExtent(thirdPart+"...",&x3,&y3);
    } while(x3 >= (2 * my_XRadius) - secondBorder);
    thirdPart += "...";
}

dc.DrawText(firstPart,absGetDrawPosition().m_x-(x/2),absGetDrawPosition().m_y - y -(y2/2));
dc.DrawText(secondPart,absGetDrawPosition().m_x-(x2/2),absGetDrawPosition().m_y - (y2/2));
dc.DrawText(thirdPart,absGetDrawPosition().m_x-(x3/2),absGetDrawPosition().m_y + (y2/2));

