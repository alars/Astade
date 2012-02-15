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
	if (theCode.GetLineCount() == 1 && theCode.GetFirstLine().StartsWith(wxS("//~~")))
		return;
}

wxString prefix;
if (op.IsInline())
	prefix = wxS("inline ");

wxString type(op.GetReturntype());
if (!type.empty())
	type += wxS(" ");

wxString postfix;
if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
	postfix = InitializerList(&op);
else if (op.IsConst())
	postfix = wxS(" const");

std::map<int, const AdeParameter*> params;
wxString paramlist(Paramlist(op, params, false));

wxString Template(source->GetTemplateString());
if (!Template.empty())
	out << "template <"
		<< source->GetTemplateString()
		<< "> ";

out << prefix
	<< type
	<< getNamespace(source->getNamespace())
	<< source->GetName();

if (!Template.empty())
{
	Template.Replace(wxS("class "), wxEmptyString);
	Template.Replace(wxS("typename "), wxEmptyString);
	out << "<"
		<< Template
		<< ">";
}

out	<< "::" << op.GetName()
	<< "("  << paramlist
	<< ")"  << postfix
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
			<< "\"" << source->GetName() << "\", "
			<< "\"" << op.GetName() << "\", "
			<< "\"" << paramlist << "\", "
			<< "\"" << type << "\")"
			<< std::endl;
	}
	else if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
	{
		hasConstructor = true;
		out << "\tNOTIFY_CONSTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << source->GetName() << "\", "
			<< "\"" << paramlist << "\")"
			<< std::endl;
	}
	else if ((op.GetType() & ITEM_IS_DEST) != 0)
	{
		hasDestructor = true;
		out << "\tNOTIFY_DESTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << source->GetName() << "\")"
			<< std::endl;
	}
}

if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
	CodePortConnections(out);

Constraints(out, op);

out << "//[" << CodeName.GetFullPath(wxPATH_UNIX)
    <<   "]" << std::endl;

if (theCode.IsOpened() && theCode.GetLineCount() > 0)
{
	wxString str;
	for (str = theCode.GetFirstLine(); !theCode.Eof(); str = theCode.GetNextLine())
		out << "\t" << str << std::endl;
	if (str.size())
		out << "\t" << str << std::endl;
}
else
	out << "\t// for roundtrip place your code here!" << std::endl;

out << "//[EOF]" << std::endl;

out << "}" << std::endl;
out << std::endl;
