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
			keyword
				= 	"asm", "auto", "bool", "false", "true", "break", "case", "catch", "char", "class", "const",
					"const_cast", "continue", "default", "defined", "delete", "do", "double", "dynamic_cast",
					"else", "enum", "explicit", "export", "extern", "float", "for", "friend", "goto", "if",
					"inline", "int", "long", "mutable", "namespace", "new", "operator", "private", "protected",
					"public", "register", "reinterpret_cast", "return", "short", "signed", "sizeof", "static",
					"static_cast", "struct", "switch", "template", "this", "throw", "try", "typedef", "typeid",
					"typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while"
				;

			Operator
				=	"&", "&&", "=", "&=", ",", ",=", "^", "^=", ",", ":", "/", "/=", ".", ".*", "...",
					"==", ">", ">=", "<", "<=", "-", "-=", "--", "%", "%=", "!", "!=", ",,", "+",
					"+=", "++", "->", "->*", "?", "::", ";", "<<", "<<=", ">>", ">>=", "*", "~",
					"*="
				;

            code
             	=	*codefragment
             	;

            codefragment
             	=	(identifier - keyword)[&g_Results->setIdentifier]
             	|	inBreakets
             	|	inBreakets2
             	|	inBreakets3
             	|	comment[&g_Results->setComment]
             	|	cstring[&g_Results->setStringConstant]
             	|	(keyword >> eps_p)[&g_Results->setKeyword]
            	|	(Operator >> eps_p)[&g_Results->setOperator]
             	|	unknown[&g_Results->setUnknown]
             	;

            comment
             	=	(comment_p("/*", "*/")
				|	comment_p("//"))
				;

            cstring
             	=	confix_p('"', *(c_escape_ch_p - eol_p), '"')
				;

			inBreakets
				=	confix_p(str_p("(")[&g_Results->setOperator], *codefragment, str_p(")")[&g_Results->setOperator])[&g_Results->setBracket]
				;

			inBreakets2
				=	confix_p(str_p("{")[&g_Results->setOperator], *codefragment, str_p("}")[&g_Results->setOperator])[&g_Results->setBracket]
				;

			inBreakets3
				=	confix_p(str_p("[")[&g_Results->setOperator], *codefragment, str_p("]")[&g_Results->setOperator])[&g_Results->setBracket]
				;

          	identifier
                =   (lexeme_d[+(alpha_p | ch_p('_')) >> *(alnum_p | ch_p('_')) ])
                ;

            unknown
             	=	(anychar_p - end_p)
				;
        }

        rule<ScannerT>	codefragment, code, comment, unknown, cstring, identifier, inBreakets, inBreakets2, inBreakets3;
		symbols<> keyword;
		symbols<> Operator;


        rule<ScannerT> const&
        start() const { return code; }

    };
};