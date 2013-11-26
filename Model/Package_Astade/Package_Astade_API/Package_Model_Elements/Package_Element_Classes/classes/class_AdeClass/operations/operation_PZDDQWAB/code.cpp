//~~ wxString GetLabel() [AdeClass] ~~
wxString FullName = GetFullName();

if (myConfig->Read(wxS("Astade/FullName"), wxEmptyString) != FullName)
{
    myConfig->Write(wxS("Astade/FullName"),FullName);
}

return myConfig->Read(wxS("Astade/Name"), wxS("<name unknown>"));
