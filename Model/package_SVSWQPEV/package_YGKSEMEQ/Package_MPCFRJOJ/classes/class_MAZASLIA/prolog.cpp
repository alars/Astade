#include <boost/spirit/core.hpp>
#include <boost/spirit/utility.hpp>

#include "CodeEditControl.h"

using namespace std;
using namespace boost::spirit;

CodeEditControl* g_Results;

struct cppGrammar : public grammar<cppGrammar>
{
    template <typename ScannerT>
    struct definition
    {
        definition(cppGrammar const& /*self*/)
        {
             code
             	=	*codefragment
             	;

             codefragment
             	=	comment
             	|	cstring
             	|	unknown
             	;

             comment
             	=	(comment_p("/*", "*/")
				|	comment_p("//"))[&g_Results->setComment]
				;

             cstring
             	=	confix_p('"', *c_escape_ch_p, '"')[&g_Results->setStringConstant]
				;

             unknown
             	=	anychar_p - end_p
				;
        }

        rule<ScannerT>	codefragment, code, comment, unknown, cstring;

        rule<ScannerT> const&
        start() const { return code; }

    };
};