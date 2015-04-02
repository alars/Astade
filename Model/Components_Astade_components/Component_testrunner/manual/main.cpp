#include <stdio.h>
#include <argp.h>

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

  return 0;
}