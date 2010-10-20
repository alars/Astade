//~~ void NotifyIsInComponent(AdeComponent& component) [AdeModelElement] ~~

myConfig->Write(wxS("Components/") + component.GetGUID(), true);
myConfig->Flush();
