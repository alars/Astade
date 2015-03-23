//~~ void Roundtrip(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxTreeItemId anID = myTree->GetSelection();

wxFileName component(theConfig->Read(wxS("TreeView/ActiveComponent")));
component.AppendDir(wxS("auto"));
component.SetName(myTree->GetItem(anID)->GetName());
component.SetExt(wxS("c"));

if (!component.FileExists())
    component.SetExt(wxS("cpp"));

for (int i = 0; i < 2; i++)
{
    if (component.FileExists())
    {
        wxTextFile aTextFile(component.GetFullPath());
        aTextFile.Open();

        for (wxString str = aTextFile.GetFirstLine(); !aTextFile.Eof(); str = aTextFile.GetNextLine())
        {
            long end;
            if (str.Find(wxS("//[")) == 0 && (end = str.Find(wxS("]"))) > 6) // dont't find the EOF
            {
                wxTextFile outFile(str.Mid(3, end - 3));
                outFile.Open();
                outFile.Clear();

                bool isCodedFile = str.Find(wxS("code.")) != wxNOT_FOUND;

                unsigned int search = aTextFile.GetCurrentLine() + 1;
                long tabsize = wxConfigBase::Get()->Read(wxS("TreeView/Tabsize"), 4);
                wxString blanks;
                blanks.Pad(tabsize);

                while (search < aTextFile.GetLineCount() && aTextFile[search].Find(wxS("//[")) != 0)
                {
                    wxString aLine = aTextFile[search];

                    if (isCodedFile)
                    {
                        if (aLine.Find(wxS("\t")) == 0)
                            aLine.Remove(0,1);
                        else if (aLine.Find(blanks) == 0)
                            aLine.Remove(0, tabsize);
                    }

                    outFile.AddLine(aLine.Trim());
                    search++;
                }
                while (outFile.GetLineCount() > 0 && outFile.GetLastLine() == wxEmptyString)
                    outFile.RemoveLine(outFile.GetCurrentLine());

                outFile.Write();
            }
        }
        component.SetExt(wxS("h"));
    }
}

wxSleep(1);
CallCoder(event);
