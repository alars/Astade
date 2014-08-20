#include <map>
#include <string>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/spirit/include/qi.hpp>

typedef std::pair<std::string, boost::optional<std::string> > pair_type;
typedef std::vector<pair_type> pairs_type;

namespace qi = boost::spirit::qi;
