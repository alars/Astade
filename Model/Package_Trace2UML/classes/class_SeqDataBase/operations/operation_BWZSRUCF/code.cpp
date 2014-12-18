//~~ bool AddConnection(const wxString& string) [SeqDataBase] ~~
wxStringTokenizer aStringTokenizer(string);
SeqConnection aConnection;

if (!aStringTokenizer.HasMoreTokens())
    RETURN(false);

aConnection.sourcePtr = aStringTokenizer.GetNextToken();

if (!aStringTokenizer.HasMoreTokens())
    RETURN(false);

aConnection.sourceClass = aStringTokenizer.GetNextToken();

if (!aStringTokenizer.HasMoreTokens())
    RETURN(false);

aConnection.sourcePort = aStringTokenizer.GetNextToken();

if (!aStringTokenizer.HasMoreTokens())
    RETURN(false);

aConnection.destPtr = aStringTokenizer.GetNextToken();

if (!aStringTokenizer.HasMoreTokens())
    RETURN(false);

aConnection.destClass = aStringTokenizer.GetNextToken();

if (!aStringTokenizer.HasMoreTokens())
    RETURN(false);

aConnection.destPort = aStringTokenizer.GetNextToken();

if (aStringTokenizer.HasMoreTokens())
    RETURN(false);

myConnections.insert(aConnection);

RETURN(true);