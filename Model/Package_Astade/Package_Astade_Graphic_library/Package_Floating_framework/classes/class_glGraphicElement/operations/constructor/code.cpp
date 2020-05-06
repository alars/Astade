//~~ glGraphicElement(glGraphicPanel* parent, int zOrder) [glGraphicElement] ~~

if (objectList.empty())
{
	objectList.push_back(this);
}
else
	for (std::list<glGraphicElement*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
	{
		if ((*it)->myZOrder >= myZOrder)
		{
			objectList.insert(it, this);
			break;
		}
		else if ((*it) == objectList.back())
		{
			objectList.push_back(this);
			break;
		}
	}

myParent->PushEventHandler(this);
AddMenuFunction(wxS("delete"), wxCommandEventHandler(glGraphicElement::OnDelete));
AddMenuFunction(wxS("meta data"), wxCommandEventHandler(glGraphicElement::OnMetaData));
glChangeNotifier::Notify();
