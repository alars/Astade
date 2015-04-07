#include <stdio.h>
#include <argp.h>
#include <fstream>
#include <map>
#include <iomanip>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_multi_pass.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/fusion/container/vector.hpp>

#include <boost/foreach.hpp>
#include <boost/shared_ptr.hpp>

#include "OutText.h"
#include "Section.h"
#include "Action.h"
#include "SectionPart.h"

namespace classic = boost::spirit::classic;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;
namespace fusion = boost::fusion;

template <typename Iterator>
struct testscript
  : qi::grammar<Iterator, boost::shared_ptr<tr::SectionPart>()>
{
    testscript()
      : testscript::base_type(outText)
    {
        using phoenix::push_back;
        using boost::spirit::_val;
        using boost::phoenix::arg_names::_1;
        using qi::lit;
        using boost::phoenix::ref;


        unesc_char.add("\\a", '\a')("\\b", '\b')("\\f", '\f')("\\n", '\n')
                      ("\\r", '\r')("\\t", '\t')("\\v", '\v')
                      ("\\\\", '\\')("\\\'", '\'')("\\\"", '\"')
        ;
        
        std::string s;

        query       =  pair >> *(qi::lit(';') >> space >> pair);
        pair        =  identifier >> -('=' >> value);
        identifier  =  qi::char_("a-zA-Z_") > *qi::char_("a-zA-Z_0-9");
        value       = +qi::char_("a-zA-Z_0-9");
        space       = *(qi::lit(' ') | qi::lit('\n') | qi::lit('\t'));
        outText     = unesc_str[_val = boost::shared_ptr<tr::SectionPart>(new tr::OutText("bbb"))];
        
        unesc_str = qi::lit('"')
            >> *(unesc_char | qi::alnum | "\\x" >> qi::hex)
            >>  qi::lit('"')
        ;
    }

    qi::rule<Iterator, std::map<std::string, std::string>()> query;
    qi::rule<Iterator, std::pair<std::string, std::string>()> pair;
    qi::rule<Iterator, std::string()> identifier, value;
    qi::rule<Iterator, boost::shared_ptr<tr::SectionPart>()> outText;
    qi::rule<Iterator, tr::Action()> action;
    qi::rule<Iterator, tr::SectionPart()> sectionPart;
    qi::rule<Iterator> space;
    

    qi::rule<Iterator, std::string()> unesc_str;
    qi::symbols<char const, char const> unesc_char;

};

const char *argp_program_version =
"testrunner 0.1";

const char *argp_program_bug_address =
"<dev@astade.tigris.org>";

static struct argp_option options[] =
{
  {"target",  't', "TARGET_ADDR", 0, "the tcp address of the target.\n(e.g.: localhost:4711)"},
  {"script",  's', "SCRIPTFILE", 0, "scriptfile to execute"},
  {"quiet",   'q', 0, OPTION_ARG_OPTIONAL, "there is no output about the script progress."},
  {"report",  'r', "REPORT", OPTION_ARG_OPTIONAL, "filname to write the test report instead of to standard output"},
  {0}
};

/* This structure is used by main to communicate with parse_opt. */
struct arguments
{
  arguments(): quiet(false), reportfile(0), scriptfile(0), target(0) {}
  bool quiet;
  char *reportfile;
  char *scriptfile;
  char *target;
};

static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = (struct arguments*) state->input;

  switch (key)
    {
    case 'q':
      arguments->quiet = true;
      break;
    case 'r':
      arguments->reportfile = arg;
      break;
    case 's':
      arguments->scriptfile = arg;
      break;
    case 't':
      arguments->target = arg;
      break;
    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

static char doc[] =
"testrunner -- A program to run testscripts.";

static struct argp argp = {options, parse_opt, 0, doc};

int main (int argc, char **argv)
{
    struct arguments arguments;

    /* Where the magic happens */
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    if (!arguments.scriptfile)
    {
        printf("you must specify a script file\n");
        exit(-1);
    }

    // open file, disable skipping of whitespace
    std::ifstream in(arguments.scriptfile);
    in.unsetf(std::ios::skipws);

    // wrap istream into iterator
    boost::spirit::istream_iterator begin(in);
    boost::spirit::istream_iterator end;

    // wrap forward iterator with position iterator, to record the position
    typedef classic::position_iterator2<boost::spirit::istream_iterator>
        pos_iterator_type;
    pos_iterator_type position_begin(begin, end, arguments.scriptfile);
    pos_iterator_type position_end;

    testscript<pos_iterator_type> p;       // create instance of parser
    boost::shared_ptr<tr::SectionPart> m;  // map to receive results

    try
    {
        qi::phrase_parse(position_begin, position_end, p, qi::space, m);
        if (position_begin != position_end)
            throw qi::expectation_failure<pos_iterator_type>(position_begin, position_end,boost::spirit::info(""));
    }
    catch(const qi::expectation_failure<pos_iterator_type> e)
    {
        const classic::file_position_base<std::string>& pos = e.first.get_position();
        std::cout   << "parse error at file "
                    << pos.file 
                    << " line " 
                    << pos.line 
                    << " column " 
                    << pos.column 
                    << std::endl
                    << "'" 
                    << e.first.get_currentline() 
                    << "'" << std::endl 
                    << std::setw(pos.column) 
                    << " " 
                    << "^- here" 
                    << std::endl;
        return -1;    
    }
    
    (*m).info();
    
    return 0;
}
