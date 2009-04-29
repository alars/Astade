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
int first = 0;

do
{
    dc.GetTextExtent(myLabel.Mid(0,++first),&x,&y);
} while (x < (2 * my_XRadius) - firstBorder);

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

if (x2 < (2 * my_XRadius) - firstBorder)
{
    dc.DrawText(firstPart,absGetDrawPosition().m_x-(x/2),absGetDrawPosition().m_y - y);
    dc.DrawText(secondPart,absGetDrawPosition().m_x-(x2/2),absGetDrawPosition().m_y);
    return;
}

// Fits in three lines?

first = 0;

do
{
    dc.GetTextExtent(myLabel.Mid(0,++first),&x,&y);
} while (x < (2 * my_XRadius) - secondBorder);


firstPart = myLabel.Mid(0,--first);

if (firstPart.Find(' ',true) > (int)(firstPart.size()/2))
    first = firstPart.Find(' ',true);
else if (firstPart.Find('-',true) > (int)(firstPart.size()/2))
    first = firstPart.Find('-',true)+1;

firstPart = myLabel.Mid(0,first);
firstPart.Trim(true);
firstPart.Trim(false);
dc.GetTextExtent(firstPart,&x,&y);

int second = 0;

do
{
    dc.GetTextExtent(myLabel.Mid(first,++second),&x2,&y2);
} while (x2 < (2 * my_XRadius) - middleBorder);


secondPart = myLabel.Mid(first,--second);

if (secondPart.Find(' ',true) > (int)(secondPart.size()/2))
    second = secondPart.Find(' ',true);
else if (secondPart.Find('-',true) > (int)(secondPart.size()/2))
    second = secondPart.Find('-',true)+1;

secondPart = myLabel.Mid(first,second);
secondPart.Trim(true);
secondPart.Trim(false);
dc.GetTextExtent(secondPart,&x2,&y2);

wxString thirdPart = myLabel.Mid(first+second);
thirdPart.Trim(true);
thirdPart.Trim(false);
wxCoord x3,y3;
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

