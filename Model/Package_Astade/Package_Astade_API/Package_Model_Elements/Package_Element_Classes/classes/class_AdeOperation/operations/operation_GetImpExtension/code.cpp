//~~ wxString GetImpExtension() [AdeOperation] ~~

wxString extension;
AdeClass* aClass = dynamic_cast<AdeClass*>(GetGrandParent());
if (aClass)
{
    extension = aClass->GetImpExtension();
    delete aClass;
}

return extension;
