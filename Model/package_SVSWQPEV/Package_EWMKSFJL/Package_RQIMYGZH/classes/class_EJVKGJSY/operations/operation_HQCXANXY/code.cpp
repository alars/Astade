int dpx = absGetDrawPosition().xCoord();
int dpy = absGetDrawPosition().yCoord();
int mpx = myParent->getMousePosition().xCoord();
int mpy = myParent->getMousePosition().yCoord();

int x,y,w,h;

if (dpx < mpx)
{
	x = dpx - 1;
	w = mpx - dpx + 2;
}
else
{
	x = mpx - 1;
	w = dpx - mpx + 2;
}

if (dpy < mpy)
{
	y = dpy - 1;
	h = mpy - dpy + 2;
}
else
{
	y = mpy - 1;
	h = dpy - mpy + 2;
}

RefreshRect(wxRect(x,y,w,h));
