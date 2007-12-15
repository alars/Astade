if (theThickness < 0)
	return;

int startY = dataBase->GetTime2Y(timeIndex);
int length = startY - dataBase->GetTime2Y(timeIndex - 1);

if (length <= 0)
	return;

if (theThickness > 4)
	theThickness = 4;

int middle = dataBase->GetClassMiddle(classIndex);

if (theThickness == 0)
{
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(_T("SEA GREEN")), 1, wxDOT_DASH));
	//dc.DrawLine(middle, startY, middle, startY - length - 1);
	for (int i = startY - length; i < startY; i++)
		if ((i % 16) < 7)
			dc.DrawPoint(middle, i);
}
else if (theThickness >= 1)
{
	for (int i = 0; i < theThickness * 5; i += 5)
	{

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(_T("WHITE")), 1, wxSOLID));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(_T("WHITE")), wxSOLID));
		dc.DrawRectangle(middle - 5 + i, startY - length, 10, length);

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(_T("SEA GREEN")), 1, wxSOLID));
		dc.DrawLine(middle - 5 + i, startY, middle - 5 + i, startY - length - 1);
		dc.DrawLine(middle + 5 + i, startY, middle + 5 + i, startY - length - 1);
	}
}
