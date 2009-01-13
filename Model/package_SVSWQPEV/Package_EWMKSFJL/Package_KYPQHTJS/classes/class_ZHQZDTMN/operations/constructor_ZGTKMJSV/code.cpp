objectList.insert(this);
myParent->PushEventHandler(this);
AddMenuFunction("delete",wxCommandEventHandler(glGraphicElement::OnDelete));