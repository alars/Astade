//~~ bool GetLabelIsUnderlined() [AstadePackage] ~~
AdePackage* me = dynamic_cast<AdePackage*>(myModelElement);
return (me && me->isNamespace());
