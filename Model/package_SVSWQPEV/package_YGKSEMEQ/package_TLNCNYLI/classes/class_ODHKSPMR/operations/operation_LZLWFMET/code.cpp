		wxConfigBase* theConfig = wxConfigBase::Get();
wxTreeItemId aID = myTree->GetSelection();

wxFileName component(theConfig->Read("TreeView/ActiveComponent"));
component.AppendDir("auto");
component.SetName(myTree->GetItem(aID)->GetName());
component.SetExt("c");

if (!component.FileExists())
	component.SetExt("cpp");

for (int i=0; i<2; i++)
{
	if (component.FileExists())
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

				bool isCodedFile = (str.Find("code.") != wxNOT_FOUND);

				unsigned int search = aTextFile.GetCurrentLine()+1;
				long tabsize = wxConfigBase::Get()->Read("TreeView/Tabsize",4);
				wxString blanks;
				blanks.Pad(tabsize);

				while (search < aTextFile.GetLineCount() && (aTextFile[search].Find(_T("//[")) != 0))
				{
					wxString aLine = aTextFile[search];

					if (isCodedFile)
					{
						if (aLine.Find("\t")==0)
							aLine.Remove(0,1);
						else if (aLine.Find(blanks.c_str())==0)
							aLine.Remove(0,tabsize);
					}

					outFile.AddLine(aLine.Trim());
					search++;
				}
				while(outFile.GetLineCount()>0 && outFile.GetLastLine()==wxEmptyString)
					outFile.RemoveLine(outFile.GetCurrentLine());

				outFile.Write();
			}
		}
		component.SetExt("h");
	}
}

wxSleep(1);
CallCoder(event);
