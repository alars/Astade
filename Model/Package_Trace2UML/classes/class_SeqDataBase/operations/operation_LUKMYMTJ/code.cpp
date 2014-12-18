//~~ void FindSlot(const wxString& string) [SeqDataBase] ~~
wxStringTokenizer aStringTokenizer(string);
SeqConnection aConnection;

if (!aStringTokenizer.HasMoreTokens())
    return;

wxString ptr = aStringTokenizer.GetNextToken();

if (!aStringTokenizer.HasMoreTokens())
    return;

wxString port = aStringTokenizer.GetNextToken();

if (aStringTokenizer.HasMoreTokens())
    return;

wxString newLine;


for (std::set<SeqConnection>::iterator it = myConnections.begin(); it != myConnections.end(); it++)
{
    if (((*it).destPtr == ptr) && ((*it).destPort==port))
    {
        newLine = wxS("??? --> ") + 
                    (*it).destPtr + 
                    wxS(":") + 
                    (*it).destClass;
        AddLine(newLine);
        return;
    }
}
