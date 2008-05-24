wxConfigBase* theConfig = wxConfigBase::Get();
wxTreeItemId aID = myTree->GetSelection();

wxFileName component(theConfig->Read("TreeView/ActiveComponent"));
component.AppendDir("auto");
component.SetName(myTree->GetItem(aID)->GetName());
component.SetExt("c");

if (!component.FileExists())
    component.SetExt("cpp");

if (!component.FileExists())
    return;

{
    wxTextFile aTextFile(component.GetFullPath());
    aTextFile.Open();

    for ( wxString str = aTextFile.GetFirstLine(); !aTextFile.Eof(); str = aTextFile.GetNextLine() )
    {
        long end;
        if (str.Find(_T("//[")) == 0 && (end = str.Find(_T("]"))) > 3)
        {
            wxTextFile outFile(str.Mid(3, end - 3));
            outFile.Open();
            outFile.Clear();
            unsigned int search = aTextFile.GetCurrentLine()+1;
            while (search < aTextFile.GetLineCount() && (aTextFile[search].Find(_T("//[")) != 0))
            {
                wxString aLine = aTextFile[search];
                
                if (aLine.Find("\t")==0)
                    aLine.Remove(0,1);
                else if (aLine.Find("    ")==0)
                    aLine.Remove(0,4);
                
                outFile.AddLine(aLine);
                search++;
            }
            outFile.Write();
        }
    }
}

component.SetExt("h");

if (!component.FileExists())
    return;

{
    wxTextFile aTextFile(component.GetFullPath());
    aTextFile.Open();

    for ( wxString str = aTextFile.GetFirstLine(); !aTextFile.Eof(); str = aTextFile.GetNextLine() )
    {
        long end;
        if (str.Find(_T("//[")) == 0 && (end = str.Find(_T("]"))) > 3)
        {
            wxTextFile outFile(str.Mid(3, end - 3));
            outFile.Open();
            outFile.Clear();
            unsigned int search = aTextFile.GetCurrentLine()+1;
            while (search < aTextFile.GetLineCount() && (aTextFile[search].Find(_T("//[")) != 0))
            {
                wxString aLine = aTextFile[search];
                
                if (aLine.Find("\t")==0)
                    aLine.Remove(0,1);
                else if (aLine.Find("    ")==0)
                    aLine.Remove(0,4);
                
                outFile.AddLine(aLine);
                search++;
            }
            outFile.Write();
        }
    }
}
