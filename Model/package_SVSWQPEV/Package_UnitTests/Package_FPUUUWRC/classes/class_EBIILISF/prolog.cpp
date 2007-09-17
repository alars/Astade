#include <boost/spirit/core.hpp>
#include <iostream>
#include <string>
#include "OperationParser.h"

////////////////////////////////////////////////////////////////////////////
using namespace std;
using namespace boost::spirit;

OperationParser* g_Results;

struct operationGrammar : public grammar<operationGrammar>
{
    template <typename ScannerT>
    struct definition
    {
        definition(operationGrammar const& /*self*/)
        {
             operationdefinition
             	=	returntype
             	>>	functionname
             	;

             functionname
             	=	identifier[assign_a(g_Results->functionName)]
             	;

             classname
             	=	identifier[assign_a(g_Results->className)]
             	;

             returntype
             	=	typedefinition[assign_a(g_Results->returnType)]
             	;

             typedefinition
             	=	identifier
             	;

             identifier
                =   lexeme_d[(+alnum_p)]
                ;
        }

        rule<ScannerT>	identifier,
        				classname,
        				typedefinition,
        				operationdefinition,
        				functionname,
        				returntype;

        rule<ScannerT> const&
        start() const { return operationdefinition; }

    };
};