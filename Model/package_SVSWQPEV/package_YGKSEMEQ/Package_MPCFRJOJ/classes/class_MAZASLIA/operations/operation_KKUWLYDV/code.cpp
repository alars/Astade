wxString sourceText = GetValue();

Position begin(sourceText.c_str(), sourceText.c_str() + sourceText.size(), "");
Position end;
begin.set_tabchars(8);

cppGrammar aGrammar;    //  Our parser
g_Results = this;		//	to find the semantic actions

Freeze();
parse(begin, end, aGrammar, space_p);
Thaw();