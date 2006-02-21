std::set<wxString> filenames;

wxFileName relations(source->GetFileName());
relations.AppendDir("relations");

wxDir dir(relations.GetPath());
wxString filename;
 
bool cont = dir.GetFirst(&filename, "*.ini");
while ( cont )
{
    wxFileName FullName = relations;
    FullName.SetFullName(filename);
    wxChar* name = NULL;
    int type = 0;
 
    wxGetResource("Astade","Type",&type,FullName.GetFullPath());
    if ((0xFF00000 & type) == ITEM_IS_RELATION)
    {
        wxGetResource("Astade","PartnerPath",&name,FullName.GetFullPath());
        wxFileName PartnerDir(name);
        PartnerDir.MakeAbsolute();
        delete [] name;
        name = NULL;
        wxGetResource("Astade","RelationType",&name,FullName.GetFullPath());
        wxString RelationType(name);
        delete [] name;
        name = NULL;
        wxGetResource("Astade","Name",&name,FullName.GetFullPath());
        wxString RelationName(name);
        delete [] name;
        name = NULL;
        wxGetResource("Astade","Implementation",&name,FullName.GetFullPath());
        wxString RelationImplementation(name);
        delete [] name;
        name = NULL;
 
        wxString theClassInclude;
        {   // get the include Path for libClasses
            wxFileName partnerName = PartnerDir;
            int i = partnerName.GetDirCount();
            partnerName.RemoveDir(i-1);
            partnerName.SetName("ModelNode"); 
            partnerName.SetExt("ini");
            wxGetResource("Astade","ClassInclude",&name,partnerName.GetFullPath());
            theClassInclude = name;
            delete [] name;
            name = NULL;
        }
 
        if (RelationType=="Generalization")
        {
            wxFileName partnerName = PartnerDir;
            int i = partnerName.GetDirCount();
            partnerName.RemoveDir(i-1);
            partnerName.SetName("ModelNode");
            partnerName.SetExt("ini");
            wxGetResource("Astade","Name", &name, partnerName.GetFullPath());
            wxString PartnerClassname(name);
            delete [] name;
            name = NULL;

            if (BaseClasses)
            {
                if (!BaseClasses->empty())
                    *BaseClasses += ", ";
                *BaseClasses += "public " + PartnerClassname;
            }
        }

        if ((RelationType=="Aggregation") ||
            (RelationType=="Association") ||
            (RelationType=="Composition"))
        {
            RelationTypes[RelationName] = RelationImplementation;
        }

        if ((( spec) && (RelationType!="ImplementationDependency")) ||
            ((!spec) && (RelationType=="ImplementationDependency")))
        {
            wxFileName partnerName = PartnerDir;
            int i = partnerName.GetDirCount();
            partnerName.RemoveDir(i-1);
            partnerName.SetName("ModelNode");
            partnerName.SetExt("ini");
            wxGetResource("Astade","Name", &name, partnerName.GetFullPath());
            wxString PartnerClassname(name);
            delete [] name;
            name = NULL;
            wxString PartnerHeadername;
            PartnerHeadername.Printf("\"%s.h\"",PartnerClassname.c_str());

            if (theClassInclude.empty())
            {
                if (PartnerClassname != source->GetName())
                    filenames.insert(PartnerHeadername);
            }
            else
            {
                InsertClassInclude(filenames,theClassInclude);
            }
        }
    }
    cont = dir.GetNext(&filename);
}

std::set<wxString>::iterator it;

if (!filenames.empty())
    fprintf(f,"// Relation includes:\n");

for (it = filenames.begin(); it != filenames.end(); ++it)
{
    fprintf(f,"#include %s\n",(*it).c_str());
}
fprintf(f,"\n");
