SetVirtualSize(dataBase->GetGraphWidth(), dataBase->GetGraphHight());

wxPaintDC dc( this );
PrepareDC( dc );

DrawOnDC(dc);