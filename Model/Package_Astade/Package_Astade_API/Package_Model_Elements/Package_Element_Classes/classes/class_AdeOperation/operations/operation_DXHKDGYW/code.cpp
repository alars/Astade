//~~ wxString GetSpecExtension() [AdeOperation] ~~

wxString extension;
AdeClass* aClass = dynamic_cast<AdeClass*>(GetGrandParent());
if (aClass)
{
    extension = aClass->GetSpecExtension();
    delete aClass;
}

return extension;
