wxString sourceText = GetValue();

Position begin(sourceText.c_str(), sourceText.c_str() + sourceText.size(), "");
Position end;
begin.set_tabchars(1);

cppGrammar aGrammar;    //  Our parser
g_Results = this;		//	to find the semantic actions

innerBracket = false;
Freeze();
parse(begin, end, aGrammar, space_p);
Thaw();