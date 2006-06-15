dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"),1,wxSOLID));

wxString name = dataBase->GetClassName(objectNumber);

wxCoord w,h;
dc.GetTextExtent(name, &w, &h);
int width = dataBase->GetClassBoxWidth(objectNumber);

dc.DrawRectangle(dataBase->GetClassMiddle(objectNumber)-width/2,
				dataBase->GetTime2Y(eventNumber)-dataBase->GetClassBoxHeight(),
				width,
				dataBase->GetClassBoxHeight());

if (name.Find(":")>0)
	dc.SetFont(objectFont);
else
	dc.SetFont(classFont);

dc.SetFont(normalFont);

dc.DrawText(name, dataBase->GetClassMiddle(objectNumber)-(w/2), dataBase->GetTime2Y(eventNumber)-(h/2)-(dataBase->GetClassBoxHeight()/2));
if (name.Find(":")>0)
	dc.DrawLine(dataBase->GetClassMiddle(objectNumber)-(w/2),
				dataBase->GetTime2Y(eventNumber)+(h/2)-(dataBase->GetClassBoxHeight()/2),
				dataBase->GetClassMiddle(objectNumber)+(w/2),
				dataBase->GetTime2Y(eventNumber)+(h/2)-(dataBase->GetClassBoxHeight()/2));