//~~ void DrawAll(wxDC& dc) [glGraphicElement] ~~
for (std::list<glGraphicElement*>::iterator it = objectList.begin(); it != objectList.end(); it++)
	(*it)->Draw(dc);