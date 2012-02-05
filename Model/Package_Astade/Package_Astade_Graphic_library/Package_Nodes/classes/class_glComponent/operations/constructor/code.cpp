//~~ glComponent(glGraphicPanel* parent, long x, long y) [glComponent] ~~

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("provide interface"), wxCommandEventHandler(glComponent::OnProvide));
AddMenuFunction(wxS("use"), wxCommandEventHandler(glComponent::OnUse));
