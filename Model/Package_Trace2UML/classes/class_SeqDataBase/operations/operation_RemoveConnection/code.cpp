//~~ void RemoveConnection(const wxString& string) [SeqDataBase] ~~
wxStringTokenizer aStringTokenizer(string);
SeqConnection aConnection;

if (!aStringTokenizer.HasMoreTokens())
    return;

wxString ptr = aStringTokenizer.GetNextToken();

std::set<SeqConnection> toRemove;

for (std::set<SeqConnection>::iterator it = myConnections.begin(); it != myConnections.end(); it++)
{
    if (((*it).destPtr == ptr) || ((*it).sourcePtr == ptr))
    {
        toRemove.insert(*it);
    }
}

while (!toRemove.empty())
{
    myConnections.erase(*(toRemove.begin()));
    toRemove.erase(toRemove.begin());
}
