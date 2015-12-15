//~~ void OnDraw(wxDC& dc) [glGraphicPanel] ~~
dc.SetFont(GrafFont);
glGraphicElement::DrawAll(dc);

dc.SetPen(*wxLIGHT_GREY_PEN);
dc.DrawLine(0, borderY, borderX, borderY);
dc.DrawLine(borderX, borderY, borderX, 0);