#include <boost/spirit/include/classic_core.hpp>
#include <boost/spirit/include/classic_utility.hpp>

#include "OperationParser.h"

using namespace std;
using namespace boost::spirit::classic;

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
                =	(functionname >> parameterlist >> !constdeclare >> !initializer >> !body >> !ch_p(';') >> end_p)[assign_a(g_Results->returnType,wxEmptyString)]
                |	(returntype >> functionname >> parameterlist >> !constdeclare >> !body >> !setAbstract >> !ch_p(';') >> end_p)
                |	(+fct_specifier >> returntype >> functionname >> parameterlist >> !constdeclare >> !setAbstract >> !body >> !ch_p(';') >> end_p)
                ;

             parameterlist
                =	(ch_p('(') >> ')')
                |	confix_p('(', (list_p((qualifiedparameter | parameter), ',') | str_p("void")) ,')')
                ;

             constdeclare
                =	str_p("const")[assign_a(g_Results->isConst,1)]
                ;

             initializer
                =	ch_p(':')
                >>	*(confix_p('"', *c_escape_ch_p, '"') | (anychar_p - '{'))
                ;

             body
                =	confix_p('{', *code, '}')[&g_Results->setBody]
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
                =	(*(identifier >> scope))[&g_Results->setClassName]
                >>	(!ch_p('~') >> identifier)[&g_Results->setFunctionName]
                ;

             parameter
                =	typedefinition[&g_Results->setType]
                >>	!identifier[&g_Results->setName]
                >>	!(ch_p('=') >> defaultValue[&g_Results->setDefault])
                ;

             qualifiedparameter
                =	eps_p[&g_Results->addParameter]
                >>	(typequalifier >> typedefinition)[&g_Results->setType]
                >>	identifier[&g_Results->setName]
                >>	!(ch_p('=') >> defaultValue[&g_Results->setDefault])
                ;

             typequalifier
                =	!(lexeme_d[str_p("const") >> space_p])
                >>	(	str_p("unsigned long")
                    |	str_p("unsigned")
                    |	str_p("signed")
                    |	str_p("long")
                    )
                ;

             defaultValue
                =	confix_p('"', *c_escape_ch_p, '"')	// C-style string constant
                |	lexeme_d[+(alnum_p | ch_p('_'))]
                ;

             typeidentifier
                =	list_p(identifier, scope)
                ;

             returntype
                =	(typedefinition - fct_specifier)[&g_Results->setReturnType]
                ;

             typedefinition
                =	!str_p("const")
                >>  !str_p("struct")
                >>  !str_p("unsigned")
                >>	typeidentifier
                >>	!comment_nest_p('<', '>')
                >>	*str_p("*")
                >>	*confix_p('[',*(alnum_p | ch_p('_')),']')
                >>	!(lexeme_d[str_p("const") >> (space_p | ch_p('*') | ch_p('&'))])
                >>	*str_p("*")
                >>	!(lexeme_d[str_p("const") >> space_p])
                >>	!str_p("&")
                ;

             scope
                = str_p("::")
                ;

            setAbstract
                =  (str_p("=") 
                >> str_p("0"))[assign_a(g_Results->isAbstract,1)]
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
                        bodycode,
                        defaultValue,
                        typequalifier,
                        qualifiedparameter,
                        setAbstract;

        rule<ScannerT> const&
        start() const { return operationdefinition; }

    };
};
