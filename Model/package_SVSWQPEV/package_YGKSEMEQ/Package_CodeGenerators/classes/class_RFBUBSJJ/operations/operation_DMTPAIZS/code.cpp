wxFileName attributes(source->GetFileName());
attributes.AppendDir("types");
 
if (wxDir::Exists(attributes.GetPath()))
{
    wxDir dir(attributes.GetPath());
    wxString filename;
 
    bool cont = dir.GetFirst(&filename, "*.ini");
    while ( cont )
    {
        wxFileName FullName = attributes;
        FullName.SetFullName(filename);
        wxChar* name = NULL;
        int type = 0;
 
        wxGetResource("Astade","Type",&type,FullName.GetFullPath());
        if (((0xFF00000 & type) == ITEM_IS_TYPE))
        {
            wxGetResource("Astade","Declaration",&name,FullName.GetFullPath());
            wxString theName(Decode(name));
            delete [] name;
            name = NULL;
 
            fprintf(f,"\t%s\n",theName.c_str());
        }    
        cont = dir.GetNext(&filename);
    }
}
