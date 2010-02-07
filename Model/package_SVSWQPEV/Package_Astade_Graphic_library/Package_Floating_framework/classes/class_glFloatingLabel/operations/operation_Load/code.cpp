glFloatingItem::Load( configObject );

wxString aText;

configObject.Read("Text", &aText);
aText.Trim(false);
aText.Trim(true);
aText.Replace("\t"," ");
aText.Replace("\n"," ");
aText.Replace("  "," ");
myText=aText;