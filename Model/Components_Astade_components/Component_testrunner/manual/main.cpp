#include <stdio.h>
#include <argp.h>
#include <fstream>
#include <map>
#include <iomanip>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_multi_pass.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>
#include <boost/fusion/include/std_pair.hpp>

namespace classic = boost::spirit::classic;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

template <typename Iterator>
struct keys_and_values
  : qi::grammar<Iterator, std::map<std::string, std::string>()>
{
    keys_and_values()
      : keys_and_values::base_type(query)
    {
        query =  pair >> *((qi::lit(';') | '&') >> pair);
        pair  =  key >> -('=' >> value);
        key   =  qi::char_("a-zA-Z_") >> *qi::char_("a-zA-Z_0-9");
        value = +qi::char_("a-zA-Z_0-9");
    }
    qi::rule<Iterator, std::map<std::string, std::string>()> query;
    qi::rule<Iterator, std::pair<std::string, std::string>()> pair;
    qi::rule<Iterator, std::string()> key, value;
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

    keys_and_values<pos_iterator_type> p;          // create instance of parser
    std::map<std::string, std::string> m;          // map to receive results

    try
    {
        qi::parse(position_begin, position_end, p, m);
    }
    catch(const qi::expectation_failure<pos_iterator_type> e)
    {
        const classic::file_position_base<std::string>& pos =
            e.first.get_position();
        std::stringstream msg;
        msg <<
            "parse error at file " << pos.file <<
            " line " << pos.line << " column " << pos.column << std::endl <<
            "'" << e.first.get_currentline() << "'" << std::endl <<
            std::setw(pos.column) << " " << "^- here";
        throw std::runtime_error(msg.str());    
    }
    
    printf("map.size = %d\n",m.size());
    
    return 0;
}