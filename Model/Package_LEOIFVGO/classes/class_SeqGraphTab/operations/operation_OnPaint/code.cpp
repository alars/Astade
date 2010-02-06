SetVirtualSize(dataBase->GetGraphWidth(), dataBase->GetGraphHeight());

wxPaintDC dc(this);
DoPrepareDC(dc);

int xScroll;
CalcUnscrolledPosition(0,0,&xScroll, &m_scroll);

int winWidth, winHight;
GetSize(&winWidth, &winHight);

m_scrollEnd = m_scroll + winHight + 50;
m_scroll -= 50;

DrawOnDC(dc, true);
