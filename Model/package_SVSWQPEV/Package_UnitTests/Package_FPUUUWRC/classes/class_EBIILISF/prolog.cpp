#include <boost/spirit/core.hpp>
#include <boost/spirit/utility.hpp>

#include "OperationParser.h"

using namespace std;
using namespace boost::spirit;

OperationParser* g_Results;

struct skipGrammar : public grammar<skipGrammar>
{
    template <typename ScannerT>
    struct definition
    {
        definition(skipGrammar const& /*self*/)
        {
			whitespace
				=	space_p						// blank space
				|	comment_p("/*", "*/")  		// C-style comment
				|	comment_p("//")				// C++ style comment
				;

	    }

	    rule<ScannerT>	whitespace;

        rule<ScannerT> const&
        start() const { return whitespace; }

    };
};

struct operationGrammar : public grammar<operationGrammar>
{
    template <typename ScannerT>
    struct definition
    {
        definition(operationGrammar const& /*self*/)
        {
             operationdefinition
             	=	returntype
             	>>	fullfunctionname
             	>>	parameterlist
             	>>	body
             	;

             parameterlist
             	=	confix_p('(', *(anychar_p - ')'),')');
             	;

             fullfunctionname
             	=	(classname >> str_p("::") >> functionname)
             	|	functionname[assign_a(g_Results->className, wxEmptyString)]
             	;

             body
             	=	confix_p('{', *code, '}')[assign_a(g_Results->functionBody)]
             	;

			 code
			 	=	comment_p("/*", "*/")  				// C-style comment
				|	comment_p("//")						// C++ style comment
				|	confix_p('"', *c_escape_ch_p, '"')	// C-style string constant
				|	confix_p('{', (*code), '}')
				|	str_p("'}'")
				|	(anychar_p - '}')
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
        				returntype,
        				body,
        				code,
        				fullfunctionname,
        				parameterlist;

        rule<ScannerT> const&
        start() const { return operationdefinition; }

    };
};