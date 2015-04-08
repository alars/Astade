#include <stdio.h>
#include <argp.h>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>

#include <boost/shared_ptr.hpp>

#include "OutText.h"
#include "Section.h"
#include "Action.h"
#include "SectionPart.h"

namespace classic = boost::spirit::classic;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

/* This structure is used by main to communicate with parse_opt. */
struct Arguments
{
  Arguments(): quiet(false), verbose(false), reportfile(0), scriptfile(0), target(0) {}
  bool quiet;
  bool verbose;
  char *reportfile;
  char *scriptfile;
  char *target;
};

Arguments arguments;

std::map<std::string, boost::shared_ptr<tr::Section> > ast;  // map to receive results
std::map<std::string, boost::shared_ptr<tr::Section> >& currentSection = ast;

void newSection(const std::string& name)
{
    if (arguments.verbose)
    {
        std::cout << "found section \"" << name << "\"" << std::endl;
    }
    if (currentSection.find(name) != currentSection.end())
        throw std::string("duplicate name \"")+name+"\"";
    boost::shared_ptr<tr::Section> aSection(new tr::Section);
    currentSection[name] = aSection;
}

template <typename Iterator>
struct testscript
  : qi::grammar<Iterator, std::vector<std::string>()>
{
    testscript()
      : testscript::base_type(rootSections)
    {
        using qi::lit;

        unesc_char.add("\\a", '\a')("\\b", '\b')("\\f", '\f')("\\n", '\n')
                      ("\\r", '\r')("\\t", '\t')("\\v", '\v')
                      ("\\\\", '\\')("\\\'", '\'')("\\\"", '\"')
        ;
        
        rootSections    = *section;
        section         %= space >> (lit("section") >> space >> identifier >> space >> lit("{") >> space >> lit("}") >> space >> lit(";"))[newSection];
        identifier      =  qi::char_("a-zA-Z_") > *qi::char_("a-zA-Z_0-9");
        space           = *(qi::lit(' ') | qi::lit('\n') | qi::lit('\t'));
        
        unesc_str = qi::lit('"')
            >> *(unesc_char | qi::alnum | "\\x" >> qi::hex)
            >>  qi::lit('"')
        ;
    }

    qi::rule<Iterator, std::string()> identifier;
    qi::rule<Iterator> space;
    qi::rule<Iterator,std::string()> section;
    qi::rule<Iterator,std::vector<std::string>()> rootSections;

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
  {"verbose", 'v', 0, OPTION_ARG_OPTIONAL, "verbose info aboout parsing."},
  {"quiet",   'q', 0, OPTION_ARG_OPTIONAL, "there is no output about the script progress."},
  {"report",  'r', "REPORT", OPTION_ARG_OPTIONAL, "filname to write the test report instead of to standard output"},
  {0}
};

static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
  Arguments* arguments = (Arguments*) state->input;

  switch (key)
    {
    case 'q':
      arguments->quiet = true;
      break;
    case 'v':
      arguments->verbose = true;
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

    try
    {
        std::vector<std::string> s;
        qi::phrase_parse(position_begin, position_end, p, qi::space, s);
        if (position_begin != position_end)
            throw qi::expectation_failure<pos_iterator_type>(position_begin, position_end,boost::spirit::info("general error"));
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
                    << e.what_
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
    catch(std::string e)
    {
        std::cout   << "logical error: "
                    << e
                    << std::endl;
        return -1;
    }

    return 0;
}
