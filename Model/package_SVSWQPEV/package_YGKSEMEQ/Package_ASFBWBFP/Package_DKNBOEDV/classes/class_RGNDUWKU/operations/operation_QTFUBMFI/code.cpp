wxPaintDC dc(this);

int x,y;

GetPosition(&x, &y);
dc.SetDeviceOrigin(x, y);

DoPaint(dc);