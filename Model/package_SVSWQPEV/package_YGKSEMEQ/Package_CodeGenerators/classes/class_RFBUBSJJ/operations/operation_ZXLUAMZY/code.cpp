std::map<wxString,wxString> operationnames;
std::map<wxString,wxString> operationtypes;
std::map<wxString,wxTextFile*> code;
std::set<wxString> operationvirtual;
std::set<wxString> operationabstract;
std::set<wxString> operationconst;
std::set<wxString> operationstatic;

wxFileName operation(source->GetFileName());
operation.AppendDir("operations");
 
if (wxDir::Exists(operation.GetPath()))
{
    wxDir dir(operation.GetPath());
    wxString filename;
 
    bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_DIRS);
    while ( cont )
    {
        wxFileName FullName = operation;
        FullName.AppendDir(filename);

        FullName.SetFullName("ModelNode.ini");
        wxChar* name = NULL;
        int type = 0;

        wxGetResource("Astade","Type",&type,FullName.GetFullPath());
        if (((0xFF00000 & type) == ITEM_IS_OPERATION) &&
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
            wxGetResource("Astade","Const",&name,FullName.GetFullPath());
            wxString Const(name);
            delete [] name;
            name = NULL;
            wxGetResource("Astade","Virtual",&name,FullName.GetFullPath());
            wxString Virtual(name);
            delete [] name;
            name = NULL;
            wxGetResource("Astade","Abstract",&name,FullName.GetFullPath());
            wxString Abstract(name);
            delete [] name;
            name = NULL;
 
            operationnames[FullName.GetFullPath()] = theName;

            if ((type&ITEM_IS_DEST)==ITEM_IS_DEST)
                operationnames[FullName.GetFullPath()] = "~" + source->GetName();
            else
            if ((type&ITEM_IS_NORMALOP)!=ITEM_IS_NORMALOP)
                operationnames[FullName.GetFullPath()] = source->GetName();
 
            if (Virtual=="yes")
            {
                operationvirtual.insert(FullName.GetFullPath());
                if (spec)
                    CodingType = "virtual " + CodingType;
            }
            if (Abstract=="yes")
                operationabstract.insert(FullName.GetFullPath());
            if (Static=="yes")
                operationstatic.insert(FullName.GetFullPath());
            if (Const=="yes")
                operationconst.insert(FullName.GetFullPath());
 
            operationtypes[FullName.GetFullPath()] = CodingType;
            wxFileName CodeName = FullName;
            CodeName.SetFullName("code.cpp");
            code[FullName.GetFullPath()] = new wxTextFile(CodeName.GetFullPath());
            if (code[FullName.GetFullPath()]->Exists())
                code[FullName.GetFullPath()]->Open(CodeName.GetFullPath());

        }
        cont = dir.GetNext(&filename);
    }
}
 
std::map<wxString,wxString>::iterator it;
 
for (it = operationnames.begin(); it != operationnames.end(); ++it)
{
    if (!spec)
    {
        fprintf(f,"\n");
 
        if (source->GetName() == (*it).second)
        {
            if (operationtypes[(*it).first].empty())
                fprintf(f,"%s::%s(%s)%s\n{\n", source->GetName().c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), InitializerList((*it).first).c_str());
            else    
                fprintf(f,"%s %s::%s(%s)%s\n{\n", operationtypes[(*it).first].c_str(), source->GetName().c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), InitializerList((*it).first).c_str());
        }
        else
        {
            wxString Const;
            if (operationconst.find((*it).first) != operationconst.end())
                Const = " const";
            if (operationtypes[(*it).first].empty())
                fprintf(f,"%s::%s(%s)%s\n{\n", source->GetName().c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), Const.c_str());
            else    
                fprintf(f,"%s %s::%s(%s)%s\n{\n", operationtypes[(*it).first].c_str(), source->GetName().c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), Const.c_str());
        }
 
        if ((code[(*it).first]->IsOpened()) && (code[(*it).first]->GetLineCount()>=1) )
        {
            wxString str;
            for ( str = code[(*it).first]->GetFirstLine(); !code[(*it).first]->Eof(); str = code[(*it).first]->GetNextLine() )
            {
                fprintf(f,"\t%s\n",str.c_str());
            }
            if (str.size())
                fprintf(f,"\t%s\n",str.c_str());
        }    
        delete code[(*it).first];
        fprintf(f,"};\n");
    }
    else
    {
        wxString Static;
        if (operationstatic.find((*it).first) != operationstatic.end())
            Static = "static ";
        wxString Const;
        if (operationconst.find((*it).first) != operationconst.end())
            Const = " const";
        wxString Abstract;
        if (operationabstract.find((*it).first) != operationabstract.end())
            Abstract = " = 0";

        if (operationtypes[(*it).first].empty())
            fprintf(f,"\t%s%s(%s)%s%s;\n", Static.c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), Const.c_str(), Abstract.c_str());
        else
            fprintf(f,"\t%s%s %s(%s)%s%s;\n", Static.c_str(), operationtypes[(*it).first].c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), Const.c_str(), Abstract.c_str());
    }
}
