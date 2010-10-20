//~~ void NotifyIsNotInComponent(AdeComponent& component) [AdeModelElement] ~~

myConfig->DeleteEntry(wxS("Components/") + component.GetGUID(), true);
myConfig->Flush();
