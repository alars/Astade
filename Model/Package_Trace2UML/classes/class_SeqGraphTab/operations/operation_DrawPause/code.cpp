int startY = dataBase->GetTime2Y(timeIndex);
int length = startY - dataBase->GetTime2Y(timeIndex - 1);

if (length <= 0)
	return;

int middle = dataBase->GetClassMiddle(classIndex);

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(_T("SEA GREEN")), 1, wxDOT_DASH));
if (theThickness >= 0)
    for (int i = startY - length; i < startY; i++)
        if ((i % 8) == 0)
            dc.DrawPoint(middle, i);
