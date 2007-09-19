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
             	=	(functionname >> parameterlist >> !constdeclare >> !initializer >> !body >> !ch_p(';') >> end_p)[assign_a(g_Results->returnType,"int")]
             	|	(returntype >> functionname >> parameterlist >> !constdeclare >> !body >> !ch_p(';') >> end_p)
             	|	(+fct_specifier >> returntype >> functionname >> parameterlist >> !constdeclare >> !body >> !ch_p(';') >> end_p)
              	;

             parameterlist
             	=	(ch_p('(') >> ')')
             	|	confix_p('(', (list_p(parameter, ',') | str_p("void")) ,')')
             	;

             constdeclare
             	=	str_p("const")[assign_a(g_Results->isConst,1)]
             	;

             initializer
             	=	ch_p(':')
             	>>	*(confix_p('"', *c_escape_ch_p, '"') | (anychar_p - '{'))
             	;

             body
             	=	confix_p('{', *code, '}')[assign_a(g_Results->functionBody)]
             	;

			 code
			 	=	comment_p("/*", "*/")  				// C-style comment
				|	comment_p("//")						// C++ style comment
				|	confix_p('"', *c_escape_ch_p, '"')	// C-style string constant
				|	confix_p('{', (*code), '}')
				|	anychar_p
			 	;

             fct_specifier
             	=	str_p("virtual")[assign_a(g_Results->isVirtual,1)]
             	|	str_p("static")[assign_a(g_Results->isStatic,1)]
             	|	str_p("inline")[assign_a(g_Results->isInline,1)]
             	;

             functionname
             	=	(*(identifier >> scope))[assign_a(g_Results->className)]
             	>>	(!ch_p('~') >> identifier)[assign_a(g_Results->functionName)]
             	;

             parameter
             	=	typedefinition[push_back_a(g_Results->parameterTypes)]
             	>>	identifier[push_back_a(g_Results->parameterNames)]
             	;

             typeidentifier
             	=	list_p(identifier, scope)
             	;

             returntype
             	=	(typedefinition - fct_specifier)[assign_a(g_Results->returnType)]
             	;

             typedefinition
             	=	!str_p("const")
             	>>	typeidentifier
             	>>	!comment_nest_p('<', '>')
             	>>	*str_p("*")
             	>>	*confix_p('[',*(alnum_p | ch_p('_')),']')
             	>>	*str_p("*")
             	>>	!(lexeme_d[str_p("const") >> space_p])
             	>>	!str_p("&")
             	;

             scope
             	= str_p("::")
             	;

             identifier
                =   lexeme_d[+(alpha_p | ch_p('_')) >> *(alnum_p | ch_p('_')) ]
                ;
        }

        rule<ScannerT>	identifier,
        				typedefinition,
        				operationdefinition,
        				functionname,
        				returntype,
        				body,
        				code,
         				parameterlist,
        				scope,
        				typeidentifier,
        				parameter,
        				fct_specifier,
        				initializer,
        				constdeclare,
        				bodycode;

        rule<ScannerT> const&
        start() const { return operationdefinition; }

    };
};