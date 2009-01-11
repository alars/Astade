if (rect==NULL)
	wxWindow::Refresh(eraseBackground, rect);
else
{
	int sx, sy;
	CalcScrolledPosition(rect->x, rect->y, &sx, &sy);
	wxRect scrolledRect(sx, sy, rect->width, rect->height);
	wxWindow::Refresh(eraseBackground, &scrolledRect);
}