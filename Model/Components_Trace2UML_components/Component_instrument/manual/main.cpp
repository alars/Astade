#include <boost/spirit/core.hpp>
#include <boost/spirit/utility.hpp>
#include <boost/spirit/iterator/file_iterator.hpp>
#include <boost/spirit/actor/push_back_actor.hpp>
#include <iostream>
#include <fstream>

///////////////////////////////////////////////////////////////////////////////

using namespace boost::spirit;

typedef char                    char_t;
typedef file_iterator<char_t>   iterator_t;
typedef scanner<iterator_t>     scanner_t;
typedef rule<scanner_t>         rule_t;

std::string output;
std::string classname;
std::string funcname;
std::string paramlist;
std::string T1;
std::string T2;

void echoC(const char c)
{
   	if (c != '\r')
    	output += c;
}


void echo(iterator_t first, iterator_t const& last)
{
    while (first != last)
    {
    	if (*first != '\r')
        	output += *first;
        ++first;
    }
}

void oneLineComment(iterator_t first, iterator_t const& last)
{
	std::string tmp;
    while (first != last)
    {
    	if (*first != '\r')
        	tmp += *first;
        ++first;
    }

	if (tmp.find("//##ModelId=",0) != std::string::npos)
		return;

    output += tmp;
}

void echobody(iterator_t first, iterator_t const& last)
{
    output += '{';

	std::string tmp;
    while (first != last)
    {
    	if (*first != '\r')
        	tmp += *first;
        ++first;
    }

	size_t s = tmp.find("NOTIFY_CONSTRUCTOR(", 0);

	if (s == std::string::npos)
		s = tmp.find("NOTIFY_DESTRUCTOR(",0);

	if (s == std::string::npos)
		s = tmp.find("NOTIFY_FUNCTION_CALL(",0);

	if (s != std::string::npos)
	{
		size_t b = tmp.rfind("\n", s);
		size_t e = tmp.find("\n", s);
		if (b != std::string::npos && e != std::string::npos)
			tmp.erase(b,e-b);
	}

    if (!classname.empty() && !funcname.empty())
    {
    	if (paramlist.size() > 30)
    		paramlist = "...";

    	if (classname == funcname)
    	{
    		// Constructor
    		output += "\n  NOTIFY_CONSTRUCTOR(5,";
    		output += "\"";
    		output += classname;
    		output += "\",\"";
    		output += paramlist;
    		output += "\")";
    	}
    	else if (funcname[0] == '~')
    	{
    		// Destructor
    		output += "\n  NOTIFY_DESTRUCTOR(5,";
    		output += "\"";
    		output += classname;
    		output += "\")";
    	}
    	else
    	{
    		// FunctionCall
    		output += "\n  NOTIFY_FUNCTION_CALL(5,";
    		output += "\"";
    		output += classname;
    		output += "\",\"";
    		output += paramlist;
    		output += "\",\"";
    		output += funcname;
    		output += "\",\"\")";
    	}
    }

    output += tmp;
    output += '}';
}

struct instrumentor : public grammar<instrumentor>
    {
    	template <typename ScannerT>
        struct definition
        {
            definition(instrumentor const& self)
            {
                identifier
                	=	(alpha_p | ch_p('_') | ch_p('~'))
                	>>	*alnum_p
                	;

                member
                	=	identifier[assign_a(T1)]
                	>>	str_p("::")
                	>>	identifier[assign_a(T2)]
                	;

                bracket
                	=	(ch_p('(') >> (*(anychar_p - ')'))[assign_a(paramlist)] >> ch_p(')'))
                	;

                codebody
	             	=	confix_p('{', (*code)[&echobody], '}')
	             	;

				 code
				 	=	comment
					|	confix_p('"', *c_escape_ch_p, '"')	// C-style string constant
					|	confix_p('{', *code, '}')
					|	anychar_p
				 	;

                comment
                	=	comment_p("/*", "*/")[&echo]
                	|	comment_p("//")[&oneLineComment]
                	;

                something
                	=	*part
                	;

                part
                    =   comment
                    |	member[assign_a(classname,T1)][assign_a(funcname,T2)][&echo]
                    |	bracket[&echo]
                    |	codebody
                    |	anychar_p[&echoC]
                    ;
			}

            rule<ScannerT> part, comment, something, identifier, member, bracket, codebody, code;

            rule<ScannerT> const&
            start() const { return something; }
        };
    };

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Must specify a filename!\n";
        return -1;
    }

    {
	    // Create a file iterator for this file
	    iterator_t first(argv[1]);

	    if (!first)
	    {
	        std::cerr << "Unable to read file! " << argv[1] << std::endl;
	        return -1;
	    }

	    // Create an EOF iterator
	    iterator_t last = first.make_end();

	    instrumentor theGrammer;    //  Our parser

	    // Parse
	    parse_info <iterator_t> info = parse(first, last, theGrammer);

		if (info.full)
	        std::cout << "Parse succeeded!\n";
	    else
	    {
	        std::cout << "Parse failed!\n";
	        return -1;
	    }
	}

	std::ofstream outStream;
	outStream.open(argv[1],std::ios::trunc);

	if( !outStream ) {
   		std::cerr << "Error opening " << argv[1] << " for writing" << std::endl;
	   	return -1;
 	}

	outStream << output;

	return 0;
}
