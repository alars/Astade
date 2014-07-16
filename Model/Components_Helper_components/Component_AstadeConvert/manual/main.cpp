#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <wx/app.h>
#include <wx/filename.h>
#include <string>
#include "AdeModel.h"


void print_usage()
{
    printf("\nAstadeConvert: utility to convert Astade models from directory structer to DSL formate\n");
    printf("Usage: AstadeConvert -m <modeldir>\n");
    printf("\nOptions:\n");
    printf("--help              Display this information\n");
    printf("-m, --model         converts the selected model.\n");
}

void generate_model(const AdeModel& aModel)
{
    printf("model {\n");
    printf("}\n");
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
        generate_model(aModel);
        wxUninitialize();
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
