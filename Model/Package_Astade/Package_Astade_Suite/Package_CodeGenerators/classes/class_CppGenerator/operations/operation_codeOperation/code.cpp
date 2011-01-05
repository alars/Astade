//~~ void codeOperation(std::ofstream& out, const AdeOperationBase& op) [CppGenerator] ~~

wxFileName CodeName(op.GetActionCodeFile());
wxTextFile theCode(CodeName.GetFullPath());
CodeName.MakeRelativeTo();
if (theCode.Exists())
	theCode.Open();
if (op.IsAbstract())
{
	if (!theCode.IsOpened() || theCode.GetLineCount() == 0)
		return;
	if (theCode.GetLineCount() == 1 && theCode.GetFirstLine().StartsWith("//~~"))
		return;
}

wxString prefix;
if (op.IsInline())
	prefix = "inline ";

wxString type(op.GetReturntype());
if (!type.empty())
	type += " ";

wxString postfix;
if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
	postfix = InitializerList(&op);
else if (op.IsConst())
	postfix = " const";

std::map<int,const AdeParameter*> params;
wxString paramlist(Paramlist(op, params, false));

wxString Template(source->GetTemplateString());
if (!Template.empty())
	out << "template <"
		<< (const char*)source->GetTemplateString().c_str()
		<< "> ";

out << (const char*)prefix.c_str()
	<< (const char*)type.c_str()
	<< (const char*)getNamespace(source->getNamespace()).c_str()
	<< (const char*)source->GetName().c_str();

if (!Template.empty())
{
	Template.Replace("class ","");
	Template.Replace("typename ","");
	out << "<"
		<< (const char*)Template.c_str()
		<< ">";
}

out	<< "::" << (const char*)op.GetName().c_str()
	<< "("  << (const char*)paramlist.c_str()
	<< ")"  << (const char*)postfix.c_str()
	<< std::endl;

out << "{" << std::endl;

int traceLevel = op.GetTraceLevel();

if (!op.IsInline() && traceLevel > 0)
{
	// Write the Tracing Macro
	if ((op.GetType() & ITEM_IS_NORMALOP) != 0)
	{
		out << "\tNOTIFY_FUNCTION_CALL("
			<< (op.IsStatic() ? "0" : "this") << ", "
			<< traceLevel << ", "
			<< "\"" << (const char*)source->GetName().c_str() << "\", "
			<< "\"" << (const char*)op.GetName().c_str() << "\", "
			<< "\"" << (const char*)paramlist.c_str() << "\", "
			<< "\"" << (const char*)type.c_str() << "\")"
			<< std::endl;
	}
	else if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
	{
		out << "\tNOTIFY_CONSTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << (const char*)source->GetName().c_str() << "\", "
			<< "\"" << (const char*)paramlist.c_str() << "\")"
			<< std::endl;

        CodePortConnections(out);
	}
	else if ((op.GetType() & ITEM_IS_DEST) != 0)
	{
		out << "\tNOTIFY_DESTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << (const char*)source->GetName().c_str() << "\")"
			<< std::endl;
	}
}

Constraints(out,op);

out << "//[" << (const char*)CodeName.GetFullPath(wxPATH_UNIX).c_str()
    <<   "]" << std::endl;

if (theCode.IsOpened() && theCode.GetLineCount() > 0)
{
	wxString str;
	for (str = theCode.GetFirstLine(); !theCode.Eof(); str = theCode.GetNextLine())
		out << "\t" << (const char*)str.c_str() << std::endl;
	if (str.size())
		out << "\t" << (const char*)str.c_str() << std::endl;
}
else
out << "\t// for roundtrip place your code here!" << std::endl;

out << "//[EOF]" << std::endl;

out << "}" << std::endl;
out << std::endl;
