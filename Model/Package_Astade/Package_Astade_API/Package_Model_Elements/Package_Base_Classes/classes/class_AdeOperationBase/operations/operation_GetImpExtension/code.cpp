//~~ wxString GetImpExtension() [AdeOperationBase] ~~

wxString extension(wxS("cpp"));
AdeClass* aClass = dynamic_cast<AdeClass*>(GetGrandParent());
if (aClass)
{
    extension = aClass->GetImpExtension();
    delete aClass;
}

return extension;
