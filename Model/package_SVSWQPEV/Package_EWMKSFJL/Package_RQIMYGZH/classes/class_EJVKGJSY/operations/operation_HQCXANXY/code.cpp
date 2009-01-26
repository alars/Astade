int dpx = absGetDrawPosition().xCoord();
int dpy = absGetDrawPosition().yCoord();
int mpx = myParent->mousePosition.xCoord();
int mpy = myParent->mousePosition.yCoord();

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

myParent->RefreshRect(wxRect(x,y,w,h));