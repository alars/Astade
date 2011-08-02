//~~ void DrawClassBox(cairo_t* cr, wxDC& dc, int eventNumber, int objectNumber) [SeqGraphTab] ~~
/* vi: set tabstop=4: */


dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("SEA GREEN")), 1, wxSOLID));

wxString name(dataBase->GetClassName(objectNumber));

int pos = name.Find(':');
if (pos >= 0 && pos != name.Find(wxS("::")))
	classFont.SetUnderlined(true);
else
	classFont.SetUnderlined(false);
dc.SetFont(classFont);

wxCoord w, h;
wxCoord w2, h2;
wxString name2;

pos = name.Find(wxS("\\n"));
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

int endY = eventNumber;
while ((endY < dataBase->GetEventsCount()) &&
       ((dataBase->GetDestinationIndex(endY) != objectNumber) ||
        ((dataBase->GetEventID(endY) != ID_GLOBALDELETE) &&
         (dataBase->GetEventID(endY) != ID_DELETE)
        )
       )
      )
    endY++;
    

setColor(cr, dashedgreen);
cairo_set_line_width (cr, 1.2);
cairo_move_to(cr, dataBase->GetClassMiddle(objectNumber), dataBase->GetTime2Y(eventNumber));
cairo_line_to (cr, dataBase->GetClassMiddle(objectNumber), dataBase->GetTime2Y(endY-1));
cairo_stroke (cr);

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
