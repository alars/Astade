operationGrammar aGrammar;    //  Our parser
skipGrammar aSkipGrammar;

g_Results = this;

parse_info<> info = parse(parseText.c_str(), aGrammar, aSkipGrammar);
parseResult = info.full;