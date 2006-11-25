/* vi: set tabstop=4: */

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"), 1, wxSOLID));

wxString name(dataBase->GetClassName(objectNumber));

int pos = name.Find(':');
if (pos >= 0 && pos != name.Find("::"))
	dc.SetFont(objectFont);
else
	dc.SetFont(classFont);

wxCoord w, h;
wxCoord w2, h2;
wxString name2;

pos = name.Find("\\n");
if (pos >= 0)
{
	name2 = name.Mid(pos + 2);
	name = name.Left(pos);

	dc.GetTextExtent(name, &w, &h);
	dc.GetTextExtent(name2, &w2, &h2);
}
else
{
	dc.GetTextExtent(name, &w, &h);
}

int width = dataBase->GetClassBoxWidth(objectNumber);

dc.DrawRectangle(dataBase->GetClassMiddle(objectNumber) - width / 2,
				dataBase->GetTime2Y(eventNumber) - dataBase->GetClassBoxHeight(),
				width,
				dataBase->GetClassBoxHeight());

if (name2.empty())
{
	dc.DrawText(name, dataBase->GetClassMiddle(objectNumber) - w / 2,
				dataBase->GetTime2Y(eventNumber) - h / 2 - dataBase->GetClassBoxHeight() / 2);
}
else
{
	dc.DrawText(name2, dataBase->GetClassMiddle(objectNumber) - w2 / 2,
				dataBase->GetTime2Y(eventNumber) - dataBase->GetClassBoxHeight() / 2 );
	dc.DrawText(name, dataBase->GetClassMiddle(objectNumber) - w / 2,
				dataBase->GetTime2Y(eventNumber) - h - dataBase->GetClassBoxHeight() / 2);
}

dc.SetFont(normalFont);
