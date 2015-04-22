#include <stdio.h>
#include <argp.h>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/spirit/include/qi_action.hpp>

#include "OutText.h"
#include "NoneAction.h"
#include "FailAction.h"
#include "Section.h"
#include "Action.h"
#include "Test.h"
#include "Trigger.h"
#include "TextTrigger.h"
#include "AnyTrigger.h"
#include "TimeoutTrigger.h"
#include "TcpRunner.h"
#include "Trace2UML.h"
#include "ReportAction.h"
#include "ExitAction.h"
#include "GotoAction.h"
#include "ShellTrigger.h"
#include "ShellAction.h"

namespace classic = boost::spirit::classic;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

/* This structure is used by main to communicate with parse_opt. */
struct Arguments
{
    Arguments(): verbose(false), beautify(false), scriptfile(0), xmlfile(0), host(0), port(0) {}
    bool verbose;
    bool beautify;
    char* scriptfile;
    char* xmlfile;
    char* host;
    int port;
};

Arguments arguments;

bool watchMode = true;
tr::Section ast(0);  // root section
tr::Section* currentSection = &ast;
tr::Trigger* currentTrigger = 0;

void newSection(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    if (arguments.verbose)
        std::cout << "found section \"" << name << "\"" << std::endl;
    if (currentSection->findSection(name))
    {
        pass = false;
        return;
    }
    tr::Section* lSection = new tr::Section(currentSection);
    boost::shared_ptr<tr::Section> aSection(lSection);
    currentSection->add(name,aSection);
    currentSection = lSection;
}

void newTest(const std::string& name, const boost::spirit::unused_type& it, bool& pass)
{
    if (arguments.verbose)
        std::cout << "found test \"" << name << "\"" << std::endl;
    if (currentSection->findSection(name))
    {
        pass = false;
        return;
    }
    tr::Section* lSection = new tr::Test(currentSection,name);
    boost::shared_ptr<tr::Section> aSection(lSection);
    currentSection->add(name,aSection);
    currentSection = lSection;
}

void endSection()
{
    if (arguments.verbose)
        std::cout << "section ended" << std::endl;
    currentSection = currentSection->getParent();
    watchMode = true;
}

void addTextTrigger(const std::string& triggerText, const boost::spirit::unused_type& it, bool& pass)
{
    if (arguments.verbose)
        std::cout << "add a text Trigger:" << std::endl;
    if (triggerText.empty())
    {
        pass = false;
        return;
    }
    currentTrigger = new tr::TextTrigger(triggerText);
    if (watchMode)
        currentSection->addWatch(boost::shared_ptr<tr::Trigger>(currentTrigger));
    else
        currentSection->addLine(boost::shared_ptr<tr::Trigger>(currentTrigger));
}

void addShellTrigger(const std::string& command, const boost::spirit::unused_type& it, bool& pass)
{
    if (arguments.verbose)
        std::cout << "add a shell Trigger:" << std::endl;
    if (watchMode)
    {
        pass = false;
        return;
    }
    currentSection->addLine(boost::shared_ptr<tr::Trigger>(new tr::ShellTrigger(command)));
}

void addAnyTrigger(boost::spirit::unused_type& t, const boost::spirit::unused_type& it, bool& pass)
{
    if (arguments.verbose)
        std::cout << "add an any Trigger:" << std::endl;

    currentTrigger = new tr::AnyTrigger();
    if (watchMode)
        pass = false;
    else
        currentSection->addLine(boost::shared_ptr<tr::Trigger>(currentTrigger));
}

void addTimeoutTrigger(boost::spirit::unused_type& t, const boost::spirit::unused_type& it, bool& pass)
{
    if (arguments.verbose)
        std::cout << "add a timeout Trigger:" << std::endl;

    currentTrigger = new tr::TimeoutTrigger();
    if (watchMode)
        currentSection->addWatch(boost::shared_ptr<tr::Trigger>(currentTrigger));
    else
        currentSection->addLine(boost::shared_ptr<tr::Trigger>(currentTrigger));
}

void newTextAction(const std::string& triggerText)
{
    if (arguments.verbose)
        std::cout << "add a text Action:" << std::endl;
    currentTrigger->addAction(boost::shared_ptr<tr::Action>(new tr::OutText(triggerText)));
}

void newShellAction(const std::string& command)
{
    if (arguments.verbose)
        std::cout << "add a shell Action:" << std::endl;
    currentTrigger->addAction(boost::shared_ptr<tr::Action>(new tr::ShellAction(command)));
}

void newGotoAction(const std::string& target, const boost::spirit::unused_type& it, bool& pass)
{
    if (arguments.verbose)
        std::cout << "add a goto(" << target << ") Action:" << std::endl;
    currentTrigger->addAction(boost::shared_ptr<tr::Action>(new tr::GotoAction(target)));
}

void newNoneAction()
{
    if (arguments.verbose)
        std::cout << "add a none Action:" << std::endl;
    currentTrigger->addAction(boost::shared_ptr<tr::Action>(new tr::NoneAction()));
}

void newFailAction()
{
    if (arguments.verbose)
        std::cout << "add a none Action:" << std::endl;
    currentTrigger->addAction(boost::shared_ptr<tr::Action>(new tr::FailAction()));
}

void newExitAction()
{
    if (arguments.verbose)
        std::cout << "add an exit Action:" << std::endl;
    currentTrigger->addAction(boost::shared_ptr<tr::Action>(new tr::ExitAction()));
}

void newReportAction(const std::string& ReportText)
{
    if (arguments.verbose)
        std::cout << "add a none Action:" << std::endl;
    currentTrigger->addAction(boost::shared_ptr<tr::Action>(new tr::ReportAction(ReportText)));
}

void startSequence(int t, const boost::spirit::unused_type& it, bool& pass)
{
    if (arguments.verbose)
        std::cout << "start sequence. Timeout=" << t << std::endl;

    if ((t < 10) || (t > 120000))
        pass = false;
    else
        currentSection->setTimeout(t);
    watchMode = false;
}

void setTestNumber(const std::string& text)
{
    if (arguments.verbose)
        std::cout << "add a test number:" << std::endl;
    currentSection->addNumber(text);
}

template <typename Iterator>
struct testscript
  : qi::grammar<Iterator, std::vector<std::string>()>
{
    testscript()
      : testscript::base_type(rootSections)
    {
        using qi::lit;
        using boost::spirit::qi::omit;
        using boost::spirit::uint_;

        unesc_char.add("\\a", '\a')("\\b", '\b')("\\f", '\f')("\\n", '\n')
                      ("\\r", '\r')("\\t", '\t')("\\v", '\v')
                      ("\\\\", '\\')("\\\'", '\'')("\\\"", '\"')("-", '-')("*",'*')
        ;
        
        rootSections    = *(section);

        section         = (section_begin | test_begin) > watchlist > sectionContent > section_end;
        sectionContent  = +(section) | omit[sequence];
        test_begin      = space >> lit("test") > space > identifier[newTest] > space > -testNumber > space > OB;
        section_begin   = space >> lit("section") > space > identifier[newSection] > space > OB;
        section_end     = (space > CB > space > SC)[endSection];


        watchlist       = *(watch);
        watch           = watch_begin > trigger > space > ARROW > space > actionlist > space > SC;
        watch_begin     = space >> lit("watch") > space > CN;


        trigger         = omit[textTrigger] | omit[shellTrigger] | anyTrigger | timeoutTrigger;
        textTrigger     = space >> unesc_str[addTextTrigger] ;
        shellTrigger    = space >> lit("shell") > space > lit("(") > space > unesc_str[addShellTrigger] > space > lit(")");
        shellAction     = space >> lit("shell") > space > lit("(") > space > unesc_str[newShellAction] > space > lit(")");
        anyTrigger      = space >> lit("always")[addAnyTrigger];
        timeoutTrigger  = space >> lit("timeout")[addTimeoutTrigger];

        actionlist      = action >> *(space >> lit(',') > action);
        action          = omit[textAction] | noneAction | omit[reportAction] | exitAction | failAction | gotoAction | shellAction;
        textAction      = space >> unesc_str[newTextAction];
        gotoAction      = space >> lit("goto") > space > lit("(") > space > identifier[newGotoAction] > space > lit(")");
        noneAction      = space >> lit("none")[newNoneAction];
        failAction      = space >> lit("fail")[newFailAction];
        exitAction      = space >> lit("exit")[newExitAction];
        reportAction    = space >> lit("report") > space > lit("(") > space > unesc_str[newReportAction] > space > lit(")");

        sequence        = space > lit("timeout") > Ob > space > timeout > space > Cb > space > CN > lineList;
        lineList        = *line;
        line            = trigger > space > ARROW > space > actionlist > space > SC;

        testNumber      = (qi::lit("[") >> (number1 | number2) >> lit("]")) [setTestNumber];

        identifier      =  qi::char_("a-zA-Z_") > *qi::char_("a-zA-Z_0-9");
        number1         =  qi::lit('\"') > *qi::char_("a-zA-Z_0-9") > qi::lit('\"') ;
        number2         =  *qi::char_("0-9");
        space           = *(qi::lit(' ') | qi::lit('\n') | qi::lit('\t'));
        OB              = lit("{");
        CB              = lit("}");
        Ob              = lit("(");
        Cb              = lit(")");
        SC              = lit(";");
        CN              = lit(":");
        ARROW           = lit("->");
        timeout         = uint_[startSequence];

        unesc_str = qi::lit('"')
                > *(unesc_char | qi::alnum | qi::char_(" ,.;:_<>|~!§$%&/()=?{[]}") | "\\x" >> qi::hex)
                >  qi::lit('"')
        ;

        actionlist.name("Expected a list of valid actions.");
        action.name("Expected a valid action.");
        identifier.name("Expected a valid (non dublicate) identifier.");
        trigger.name("Expected a valid trigger.");
        sequence.name("'timeout' expected");
        timeout.name("timeout must be between 10..120000 mSec.");

        OB.name("Expected '{'");
        CB.name("Expected '}'");
        Ob.name("Expected '('");
        Cb.name("Expected ')'");
        SC.name("Expected ';'");
        CN.name("Expected ':'");
        ARROW.name("Expected '->'");
    }

    qi::rule<Iterator, std::string()> identifier;
    qi::rule<Iterator, std::string()> number1;
    qi::rule<Iterator, std::string()> number2;
    qi::rule<Iterator, std::string()> testNumber;
    qi::rule<Iterator> space;
    qi::rule<Iterator,std::string()> section_begin;
    qi::rule<Iterator,std::string()> test_begin;
    qi::rule<Iterator> section;
    qi::rule<Iterator> section_end;
    qi::rule<Iterator> watch_begin;
    qi::rule<Iterator> watch;
    qi::rule<Iterator> trigger;
    qi::rule<Iterator,std::string()> textTrigger;
    qi::rule<Iterator,std::string()> shellTrigger;
    qi::rule<Iterator> anyTrigger;
    qi::rule<Iterator> timeoutTrigger;
    qi::rule<Iterator> actionlist;
    qi::rule<Iterator> watchlist;
    qi::rule<Iterator> noneAction;
    qi::rule<Iterator> failAction;
    qi::rule<Iterator> exitAction;
    qi::rule<Iterator> action;
    qi::rule<Iterator> sectionContent;
    qi::rule<Iterator,std::string()> textAction;
    qi::rule<Iterator,std::string()> gotoAction;
    qi::rule<Iterator,std::string()> reportAction;
    qi::rule<Iterator,std::string()> shellAction;
    qi::rule<Iterator,std::vector<std::string>()> rootSections;
    qi::rule<Iterator, unsigned int> sequence;
    qi::rule<Iterator, unsigned int> timeout;
    qi::rule<Iterator> line;
    qi::rule<Iterator> lineList;

    qi::rule<Iterator> OB;
    qi::rule<Iterator> CB;
    qi::rule<Iterator> Ob;
    qi::rule<Iterator> Cb;
    qi::rule<Iterator> SC;
    qi::rule<Iterator> CN;
    qi::rule<Iterator> ARROW;

    qi::rule<Iterator, std::string()> unesc_str;
    qi::symbols<char const, char const> unesc_char;

};

const char *argp_program_version =
"testrunner 0.1";

const char *argp_program_bug_address =
"<dev@astade.tigris.org>";

static struct argp_option options[] =
{
  {"host",    'h', "HOST ADDR",  0, "the tcp address of the target.\n(e.g.: localhost or 127.0.0.1)"},
  {"port",    'p', "HOST PORT",  0, "the port number to connect.\n(e.g.: 23)"},
  {"script",  's', "SCRIPTFILE", 0, "scriptfile to execute"},
  {"verbose", 'v', 0,            0, "verbose info aboout parsing."},
  {"trace",   't', 0,            0, "an additional debug trace (for the testrunner)."},
  {"beautify",'b', 0,            0, "output the parsed text in a beautified form."},
  {"xml"     ,'x', "XML FILE",   0, "output the test report in xml format to this file."},
  {0}
};

static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    Arguments* arguments = (Arguments*) state->input;

    switch (key)
    {
    case 'b':
        arguments->beautify = true;
        break;
    case 'v':
        arguments->verbose = true;
        break;
    case 's':
        arguments->scriptfile = arg;
        break;
    case 'h':
        arguments->host = arg;
        break;
    case 'x':
        arguments->xmlfile = arg;
        break;
    case 'p':
        arguments->port = atoi(arg);
        break;
    case 't':
        Trace2UML::ms_ofile.open("Trace2UML.seq");
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
        exit(1);
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

    if (arguments.beautify)
    {
        ast.beautify(0);
    } else {
    
        if (!arguments.host)
        {
            printf("you must specify a host name\n");
            exit(2);
        }

        if (!arguments.port)
        {
            printf("you must specify a port\n");
            exit(3);
        }

        tr::TcpRunner runner;
        tr::Action::setRunnerInterface(&runner);
        runner.setCurrentSection(&ast);
        runner.connect(arguments.host, arguments.port);
        runner.run();
    }

    return 0;
}
