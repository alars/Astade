SetVirtualSize(dataBase->GetGraphWidth(), dataBase->GetGraphHeight());

wxPaintDC dc(this);
DoPrepareDC(dc);

DrawOnDC(dc);
