operationGrammar aGrammar;    //  Our parser
g_Results = this;

parse_info<> info = parse(parseText.c_str(), aGrammar, space_p);
parseResult = info.full;