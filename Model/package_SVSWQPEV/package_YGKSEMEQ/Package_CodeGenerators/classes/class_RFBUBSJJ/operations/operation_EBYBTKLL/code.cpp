wxFileName parameterPath(Operationpath);
parameterPath.AppendDir("parameters");
wxString paramlist;

if (wxDir::Exists(parameterPath.GetPath()))
{
    wxDir dir(parameterPath.GetPath());
    wxString filename;

    bool cont = dir.GetFirst(&filename,"*.ini");

    wxString params[256];
    wxString types[256];

    while ( cont )
    {
        wxFileName newPath(parameterPath);
        newPath.SetFullName(filename);

        int type;
        wxGetResource("Astade","Type", &type, newPath.GetFullPath());

        if ((type & ITEM_IS_PARAMETER) == ITEM_IS_PARAMETER)
        {
            int number = type & 0xff;
 
            wxChar* name = NULL;
            wxGetResource("Astade","Name", &name, newPath.GetFullPath());
            params[number] = name;
            delete [] name;
            name = NULL;
            wxGetResource("Astade","CodingType", &name, newPath.GetFullPath());
            types[number] = Decode(name);
            delete [] name;
            name = NULL;
        }
 
        cont = dir.GetNext(&filename);
     }
 
     for (int i=0;i<256;++i)
     {
         if (params[i].length()!=0)
         {
             if (paramlist.length()!=0)
                 paramlist = paramlist + ",";
             paramlist = paramlist + types[i] + " " + params[i];
         }
    }
}
return paramlist;
