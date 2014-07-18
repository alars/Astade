#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <wx/app.h>
#include <wx/filename.h>
#include <string>
#include "AdeModel.h"
#include "AdeComponents.h"
#include "AdePackage.h"
#include "AdeComponent.h"
#include "ACModel.h"


void print_usage()
{
    printf("\nAstadeConvert: utility to convert Astade models from directory structer to DSL formate\n");
    printf("Usage: AstadeConvert -m <modeldir>\n");
    printf("\nOptions:\n");
    printf("--help              Display this information\n");
    printf("-m, --model         converts the selected model.\n");
}

unsigned int indent = 0;

void pIndent()
{
    for (unsigned int i = 0; i < indent; i++)
        printf("    ");
}

void generate_components(const AdeComponents& c)
{
    printf("\nproject \"%s\"{\n",c.GetLabel().mb_str().data());
    printf("}\n");
}

void generate_package(const AdePackage& p, wxString nameSpace)
{
    if (nameSpace.empty())
        printf("\npackage \"%s\"{\n",p.GetLabel().mb_str().data());
    else
        printf("\npackage \"%s::%s\"{\n",nameSpace.mb_str().data(), p.GetLabel().mb_str().data());
    indent++;
    for (AdeElementIterator it = p.begin(); it != p.end(); ++it)
    {
        AdeModelElement* anElement = it.CreateNewElement();
        AdePackage* p = dynamic_cast<AdePackage*>(anElement);
        if (p)
        {
            pIndent();
            printf("package \"%s\";\n",p->GetLabel().mb_str().data());
        }
        delete anElement;
    }
    indent--;
    printf("}\n");
}

void generate_model(const AdeModel& aModel)
{
    printf("model {\n");
    indent++;
    for (AdeElementIterator it = aModel.begin(); it != aModel.end(); ++it)
    {
        AdeModelElement* anElement = it.CreateNewElement();
        AdeComponents* c = dynamic_cast<AdeComponents*>(anElement);
        if (c)
        {
            pIndent();
            printf("project \"%s\";\n",c->GetLabel().mb_str().data());
        }
        delete anElement;
    }
    for (AdeElementIterator it = aModel.begin(); it != aModel.end(); ++it)
    {
        AdeModelElement* anElement = it.CreateNewElement();
        AdePackage* p = dynamic_cast<AdePackage*>(anElement);
        if (p)
        {
            pIndent();
            printf("package \"%s\";\n",p->GetLabel().mb_str().data());
        }
        delete anElement;
    }
    indent--;
    printf("}\n");
    for (AdeElementIterator it = aModel.begin(); it != aModel.end(); ++it)
    {
        AdeModelElement* anElement = it.CreateNewElement();
        AdeComponents* c = dynamic_cast<AdeComponents*>(anElement);
        if (c)
            generate_components(*c);
        delete anElement;
    }
    for (AdeElementIterator it = aModel.begin(); it != aModel.end(); ++it)
    {
        AdeModelElement* anElement = it.CreateNewElement();
        AdePackage* p = dynamic_cast<AdePackage*>(anElement);
        if (p)
            generate_package(*p,wxS(""));
        delete anElement;
    }
}

int main(int argc, char **argv)
{
    static struct option long_options[] = {
        {"help"       ,  no_argument,        0,  'h' },
        {"model"      ,  required_argument,  0,  'm' },
        {0,          0,                      0,   0  }
    };
    
    int long_index =0;
    int opt;
    
    wxFileName modelFile;
    
    while ((opt = getopt_long(argc, argv, "hm:", long_options, &long_index )) != -1) {
        switch (opt) {
         case 'm':
            modelFile.SetPath(wxString::FromUTF8(optarg));
            modelFile.SetFullName(wxS("ModelNode.ini"));
            break;
         case 'h':
            print_usage();
            exit(EXIT_SUCCESS);
            break;
        default:
            print_usage();
            exit (EXIT_FAILURE);
            break;
        }
    }
    
    if (wxInitialize())
    {
        AdeModel aModel(modelFile);
        ACModel(aModel).Print();
        wxUninitialize();
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
