std::map<wxString,wxString> attributenames;
std::map<wxString,wxString> attributedefaults;

wxFileName attributes(source->GetFileName());
attributes.AppendDir("attributes");
 
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
        if (((0xFF00000 & type) == ITEM_IS_ATTRIBUTE) &&
            ((type & visibility) == visibility))
        {
            wxGetResource("Astade","Name",&name,FullName.GetFullPath());
            wxString theName(name);
            delete [] name;
            name = NULL;
            wxGetResource("Astade","CodingType",&name,FullName.GetFullPath());
            wxString CodingType(name);
            delete [] name;
            name = NULL;
            wxGetResource("Astade","Static",&name,FullName.GetFullPath());
            wxString Static(name);
            delete [] name;
            name = NULL;
            wxGetResource("Astade","Default",&name,FullName.GetFullPath());
            wxString Default(name);
            delete [] name;
            name = NULL;
 
            if (Static == "yes")
            {
                attributenames[theName] = CodingType;
                if (Default.size()>0)
                    attributedefaults[theName] = Decode(Default);
            }
        }
        cont = dir.GetNext(&filename);
    }
}
 
std::map<wxString,wxString>::iterator it;
 
for (it = attributenames.begin(); it != attributenames.end(); ++it)
{
    if (spec)
        fprintf(f,"\tstatic %s\t%s;\n",(*it).second.c_str(),(*it).first.c_str());
    else
    {
        if (attributedefaults.find((*it).first)!=attributedefaults.end())
            fprintf(f,"%s %s::%s = %s;\n",(*it).second.c_str(),source->GetName().c_str(),(*it).first.c_str(),attributedefaults[(*it).first].c_str());
        else
            fprintf(f,"%s %s::%s;\n",(*it).second.c_str(),source->GetName().c_str(),(*it).first.c_str());
    }
}
