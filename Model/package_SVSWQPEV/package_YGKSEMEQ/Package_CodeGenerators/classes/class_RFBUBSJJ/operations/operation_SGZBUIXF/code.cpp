/* vi: set tabstop=4: */

wxFileName CodeName(op.GetFileName());
CodeName.SetFullName("code.cpp");
wxTextFile theCode(CodeName.GetFullPath());
CodeName.MakeRelativeTo(wxFileName::GetCwd());
if (theCode.Exists())
	theCode.Open();
if (op.IsAbstract() && (!theCode.IsOpened() || theCode.GetLineCount() == 0))
	return;

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

out << prefix
	<< type
	<< source->GetName()
	<< "::" << op.GetName()
	<< "("  << paramlist
	<< ")"  << postfix
	<< std::endl;
out << "{" << std::endl;

int traceLevel = op.GetTraceLevel();

if ((!op.IsInline()) && (!op.IsStatic()) && (traceLevel > 0))
{
	// Write the Tracing Macro
	if (typeid(op) == typeid(AdeOperation))
	{
		out << "\tNOTIFY_FUNCTION_CALL("
			<< traceLevel << ", "
			<< "\"" << source->GetName() << "\", "
			<< "\"" << op.GetName() << "\", "
			<< "\"" << paramlist << "\", "
			<< "\"" << type << "\")"
			<< std::endl;
	}
	else if (typeid(op) == typeid(AdeConstructor))
	{
		out << "\tNOTIFY_CONSTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << source->GetName() << "\","
			<< "\"" << paramlist << "\")"
			<< std::endl;
	}
	else if (typeid(op) == typeid(AdeDestructor))
	{
		out << "\tNOTIFY_DESTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << source->GetName() << "\")"
			<< std::endl;
	}
}

if (theCode.IsOpened() && theCode.GetLineCount() > 0)
{
	out << "//[" << CodeName.GetFullPath() << "]" << std::endl;
	wxString str;
	for (str = theCode.GetFirstLine(); !theCode.Eof(); str = theCode.GetNextLine())
		out << "\t" << str << std::endl;
	if (str.size())
		out << "\t" << str << std::endl;
	out << "//[EOF]" << std::endl;
}
out << "};" << std::endl;
out << std::endl;
