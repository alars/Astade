//~~ wxString GetSpecExtension() [AdeOperationBase] ~~

wxString extension(wxS("h"));
AdeClass* aClass = dynamic_cast<AdeClass*>(GetGrandParent());
if (aClass)
{
    extension = aClass->GetSpecExtension();
    delete aClass;
}

return extension;
