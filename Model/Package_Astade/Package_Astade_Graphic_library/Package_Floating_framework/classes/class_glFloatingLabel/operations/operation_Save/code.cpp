//~~ void Save(wxConfigBase& configObject) [glFloatingLabel] ~~

glFloatingItem::Save(configObject);

configObject.Write(wxS("Text"), myText);
