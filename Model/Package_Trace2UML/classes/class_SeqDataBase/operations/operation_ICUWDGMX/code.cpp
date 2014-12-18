//~~ wxString FindSignal(const wxString& string) [SeqDataBase] ~~
wxStringTokenizer aStringTokenizer(string);
SeqConnection aConnection;

if (!aStringTokenizer.HasMoreTokens())
    RETURN(wxString());

wxString ptr = aStringTokenizer.GetNextToken();

if (!aStringTokenizer.HasMoreTokens())
    RETURN(wxString());

wxString port = aStringTokenizer.GetNextToken();

if (aStringTokenizer.HasMoreTokens())
    RETURN(wxString());

wxString newLine;


for (std::vector<SeqConnection>::iterator it = myConnections.begin(); it != myConnections.end(); it++)
{
    if (((*it).sourcePtr == ptr) && ((*it).sourcePort==port))
    {
        newLine = (*it).sourcePtr + 
                    wxS(":") + 
                    (*it).sourceClass +
                    wxS(" >-- ") + 
                    (*it).destPtr + 
                    wxS(":") + 
                    (*it).destClass;
        break;
    }
}

RETURN(newLine);