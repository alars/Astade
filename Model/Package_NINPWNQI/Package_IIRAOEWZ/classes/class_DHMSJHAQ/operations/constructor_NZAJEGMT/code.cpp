//~~ pair_grammar() [pair_grammar] ~~
query =  pair >> *((boost::spirit::qi::lit(';') | '&') >> pair);
pair  =  key >> -('=' >> -value);
key   =  boost::spirit::qi::char_("a-zA-Z_") >> *boost::spirit::qi::char_("a-zA-Z_0-9");
value = +boost::spirit::qi::char_("a-zA-Z_0-9");
