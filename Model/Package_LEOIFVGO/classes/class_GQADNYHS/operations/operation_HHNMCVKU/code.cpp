if (theThickness < 0)
	return;

if (theThickness > 4)
	theThickness=4;

int startY = dataBase->GetTime2Y(timeIndex);
int middle = dataBase->GetClassMiddle(classIndex);

if (theThickness==0)
	dc.DrawLine(middle, startY-5, middle, startY+5);
else
if (theThickness>=1)
{
	for (int i=0; i<(theThickness*5); i+=5)
	{

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("WHITE"),1,wxSOLID));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"),wxSOLID));
		dc.DrawRectangle(middle-5+i, startY-10, 10, 20);

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"),1,wxSOLID));
		dc.DrawLine(middle-5+i, startY-10, middle-5+i, startY+10);
		dc.DrawLine(middle+5+i, startY-10, middle+5+i, startY+10);
	}
}
