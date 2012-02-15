//~~ OperationParser(const wxString& parseText) [OperationParser] ~~

operationGrammar aGrammar;    //  Our parser
skipGrammar aSkipGrammar;

g_Results = this;

parse_info<> info = parse((const char*)parseText.utf8_str(), aGrammar, aSkipGrammar);
parseResult = info.full;

if (parseResult)
{
	BeautifyBody();
}
