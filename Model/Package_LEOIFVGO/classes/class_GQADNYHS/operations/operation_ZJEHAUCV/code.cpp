dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"),1,wxLONG_DASH));

for (int i=0; i<dataBase->GetClassCount(); i++)
{
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"),1,wxLONG_DASH));

	dc.DrawLine(dataBase->GetClassMiddle(i),
				dataBase->UPPER_BORDER,
				dataBase->GetClassMiddle(i),
				1000);

	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"),1,wxSOLID));

	dc.DrawRectangle(dataBase->GetClassMiddle(i)-dataBase->GetClassBoxWidth()/2,
					dataBase->UPPER_BORDER,
					dataBase->GetClassBoxWidth(),
					dataBase->GetClassBoxHight()+dataBase->UPPER_BORDER);

	wxString name = dataBase->GetClassName(i);

	wxCoord w,h;

	dc.GetTextExtent(name, &w, &h);
	dc.DrawText( name, dataBase->GetClassMiddle(i)-(w/2), (dataBase->GetClassBoxHight()/2)+dataBase->UPPER_BORDER+(h/2) );
}