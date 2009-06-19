if (!glGraphicElement::destroyList.empty())
{
	glGraphicElement::destroyList.front()->Refresh();
	delete glGraphicElement::destroyList.front();
	glGraphicElement::destroyList.pop_front();
	event.RequestMore();
}
else if (stateFastest)
{
	glFloatingItem::MoveAll();
	glGraphicElement::CheckAllMouseOver();
	event.RequestMore();
	itsTimeForRedraw = false;
}else if (itsTimeForRedraw)
{
	glFloatingItem::MoveAll();
	glGraphicElement::CheckAllMouseOver();
	itsTimeForRedraw = false;
}
