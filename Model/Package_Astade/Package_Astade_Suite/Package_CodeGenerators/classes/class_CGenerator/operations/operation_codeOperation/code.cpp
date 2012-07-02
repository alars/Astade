//~~ void codeOperation(std::ofstream& out, const AdeOperationBase& op, bool doStatic) [CGenerator] ~~

wxFileName CodeName(op.GetActionCodeFile());

wxTextFile theCode(CodeName.GetFullPath());
CodeName.MakeRelativeTo();
if (theCode.Exists())
	theCode.Open();
if (op.IsAbstract() && (!theCode.IsOpened() || theCode.GetLineCount() == 0))
	return;

wxString prefix;
if (doStatic)
	prefix = wxS("static ");
if (op.IsInline())
	prefix = wxS("inline ");	// "static inline" ==> "inline"

wxString type(op.GetReturntype());
if (!type.empty())
	type += wxS(" ");

std::map<int,const AdeParameter*> params;
wxString paramlist(Paramlist(op, params, false));

if (!op.IsStatic())
{
	if (!paramlist.empty())
        paramlist = wxS(", ") + paramlist;
    paramlist = source->GetName() + wxS("* me") + paramlist;
    if (op.IsConst())
        paramlist = wxS("const ") + paramlist;
}

wxString functionName;
if ((op.GetType() & ITEM_IS_NORMALOP) != 0)
{
    functionName = op.GetName();
}
else if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
{
    functionName = wxS("Constructor");
    type = wxS("void ");
}
else if ((op.GetType() & ITEM_IS_DEST) != 0)
{
    functionName = wxS("Destructor");
    type = wxS("void ");
}

if (paramlist.empty())
    paramlist = wxS("void");

out << prefix.utf8_str()
	<< type.utf8_str()
	<< source->GetName().utf8_str()
	<< "_" << functionName.utf8_str()
	<< "(" << paramlist.utf8_str()
	<< ")" << std::endl;
out << "{" << std::endl;

int traceLevel = op.GetTraceLevel();

if (!op.IsInline() && traceLevel > 0)
{
	wxString mestr;
	if (op.IsStatic())
		mestr = wxS("0");
	else
		mestr = wxS("me");

	// Write the Tracing Macro
	if ((op.GetType() & ITEM_IS_NORMALOP) != 0)
	{
		out << "\tNOTIFY_CFUNCTION_CALL("
			<< mestr.utf8_str() << ", "
			<< traceLevel << ", "
			<< "\"" << source->GetName().utf8_str() << "\", "
			<< "\"" << op.GetName().utf8_str() << "\", "
			<< "\"" << paramlist.utf8_str() << "\", "
			<< "\"" << type.utf8_str() << "\")"
			<< std::endl;
	}
	else if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
	{
		hasConstructor = true;
		out << "\tNOTIFY_CCONSTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << source->GetName().utf8_str() << "\", "
			<< "\"" << paramlist.utf8_str() << "\")"
			<< std::endl;
	}
	else if ((op.GetType() & ITEM_IS_DEST) != 0)
	{
		hasDestructor = true;
		out << "\tNOTIFY_CDESTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << source->GetName().utf8_str() << "\")"
			<< std::endl;
	}
}

if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
{ // constructor
	out << InitializerList(&op).utf8_str();
	CodePortConnections(out);

	const AdeConstructor* pc = dynamic_cast<const AdeConstructor*>(&op);
	wxString theInitializers;
	if (pc)
		theInitializers = pc->GetInitializers();

	for (std::set<wxString>::iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
	{
		out << "\t"	<< it->utf8_str() << "_Constructor(&(me->" << it->utf8_str() << "_base)";

		wxString search = *it + wxS("_INIT");
		search.MakeUpper();

		if (theInitializers.Find(search) != wxNOT_FOUND)
			out << "," << search.utf8_str();

		out << ");"	<< std::endl;
	}
}

Constraints(out, op);

out << "//[" << CodeName.GetFullPath(wxPATH_UNIX).utf8_str()
    <<   "]" << std::endl;

if (theCode.IsOpened() && theCode.GetLineCount() > 0)
{
	wxString str;
	for (str = theCode.GetFirstLine(); !theCode.Eof(); str = theCode.GetNextLine())
		out << "\t" << search4return(str, traceLevel).utf8_str() << std::endl;
	if (str.size())
		out << "\t" << search4return(str, traceLevel).utf8_str() << std::endl;
}
else
	out << "\t// for roundtrip place your code here!" << std::endl;

out << "//[EOF]" << std::endl;

if ((op.GetType() & ITEM_IS_DEST) != 0)
{ // destructor
	for (std::set<wxString>::iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
	{
		out << "\t"
			<< it->utf8_str() << "_Destructor(&(me->" << it->utf8_str() << "_base));"
			<< std::endl;
	}
}

if (!op.IsInline() && traceLevel > 0 && type == wxS("void "))
	out << "\tvoidRETURN;" << std::endl;

out << "}" << std::endl;
out << std::endl;
