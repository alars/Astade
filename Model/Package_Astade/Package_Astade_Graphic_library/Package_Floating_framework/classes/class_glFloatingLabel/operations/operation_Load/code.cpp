//~~ void Load(wxConfigBase& configObject) [glFloatingLabel] ~~

glFloatingItem::Load(configObject);

wxString aText;

configObject.Read(wxS("Text"), &aText);
aText.Trim(false);
aText.Trim(true);
aText.Replace(wxS("\t"), wxS(" "));
aText.Replace(wxS("\n"), wxS(" "));
aText.Replace(wxS("  "), wxS(" "));
myText=aText;
