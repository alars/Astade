wxPaintDC dc(this);

dc.SetDeviceOrigin(m_Position.xCoord(), m_Position.yCoord());

DoPaint(dc);