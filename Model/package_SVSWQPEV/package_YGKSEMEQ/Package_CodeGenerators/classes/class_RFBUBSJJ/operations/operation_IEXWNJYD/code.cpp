wxFileName parameterPath(Operationpath);
wxChar* name = NULL;
wxGetResource("Astade","Initializer", &name, Operationpath);
wxString paramlist(Decode(name));
if (!paramlist.empty())
    paramlist = ":\n\t" + paramlist;
delete name;
 
while (!AttributeList.empty())
{
    if (!memberDefaults[AttributeList.front()].empty())
    {
        if (paramlist.empty())
            paramlist = ":\n\t" + AttributeList.front() + "(" + memberDefaults[AttributeList.front()] + ")";
        else
            paramlist = paramlist + ",\n\t" + AttributeList.front() + "(" + memberDefaults[AttributeList.front()] + ")";
    }
    AttributeList.pop_front();
}
return paramlist;
