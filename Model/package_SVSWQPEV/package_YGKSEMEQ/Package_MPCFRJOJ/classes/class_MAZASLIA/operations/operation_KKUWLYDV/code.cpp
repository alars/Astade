wxString sourceText = GetValue();

parsingData = (char*)sourceText.c_str();

cppGrammar aGrammar;    //  Our parser

g_Results = this;

parse_info<> info = parse(parsingData, aGrammar, space_p);