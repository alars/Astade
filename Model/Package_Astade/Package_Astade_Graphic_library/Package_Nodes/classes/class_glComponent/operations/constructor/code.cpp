//~~ glComponent(glGraphicPanel* parent, long x, long y) [glComponent] ~~
Refresh();
AddMenuSeparator();
AddMenuFunction("provide interface",wxCommandEventHandler(glComponent::OnProvide));
AddMenuFunction("use",wxCommandEventHandler(glComponent::OnUse));
