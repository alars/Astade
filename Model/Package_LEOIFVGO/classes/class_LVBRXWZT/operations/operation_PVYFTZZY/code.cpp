wxTextFile aTextFile(inFile);
SeqDataBase aDataBase(0);

if (aTextFile.Exists())
{
    aTextFile.Open();

    if (aTextFile.IsOpened())
    {
        wxString str;
        aDataBase.Clear();
        for ( str = aTextFile.GetFirstLine(); !aTextFile.Eof(); str = aTextFile.GetNextLine() )
            aDataBase.AddLine(str);
            
        aDataBase.AddLine(str);
        
        SeqGraphTab aGraphTab(0, &aDataBase);

        {
            // First Round is, to find out the needed size
            wxBitmap theBitmap(aDataBase.GetGraphWidth(), aDataBase.GetGraphHeight());
     
            wxMemoryDC dc;
            dc.SelectObject(theBitmap);
            dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"), wxSOLID));
            dc.Clear();

            aGraphTab.DrawOnDC(dc);
            dc.SelectObject(wxNullBitmap);
        }

        wxBitmap theBitmap(aDataBase.GetGraphWidth(), aDataBase.GetGraphHeight());
 
        wxMemoryDC dc;
        dc.SelectObject(theBitmap);
        dc.SetBackground(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"), wxSOLID));
        dc.Clear();

        aGraphTab.DrawOnDC(dc);

        dc.SelectObject(wxNullBitmap);
        theBitmap.ConvertToImage().SaveFile(outFile);
    }
}
