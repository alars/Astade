//~~ wxString GetLabel() [AdeClass] ~~
wxString FullName = GetFullName();

if (myConfig->Read(wxS("Astade/FullName"), wxEmptyString) != FullName)
{
    myConfig->Write(wxS("Astade/FullName"),FullName);
    myConfig->Flush();
}

return myConfig->Read(wxS("Astade/Name"), wxS("<name unknown>"));
