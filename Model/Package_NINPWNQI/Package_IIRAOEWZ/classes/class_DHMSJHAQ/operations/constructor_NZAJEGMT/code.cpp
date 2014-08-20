//~~ key_value_sequence_empty_value() [key_value_sequence_empty_value] ~~
query =  pair >> *((qi::lit(';') | '&') >> pair);
pair  =  key >> -('=' >> -value);
key   =  qi::char_("a-zA-Z_") >> *qi::char_("a-zA-Z_0-9");
value = +qi::char_("a-zA-Z_0-9");
