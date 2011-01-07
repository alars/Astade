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
	prefix = "static ";
if (op.IsInline())
	prefix = "inline ";	// "static inline" ==> "inline"

wxString type(op.GetReturntype());
if (!type.empty())
	type += " ";

std::map<int,const AdeParameter*> params;
wxString paramlist(Paramlist(op, params, false));

if (!op.IsStatic())
{
	if (!paramlist.empty())
        paramlist = ", " + paramlist;
    paramlist = source->GetName() + "* me" + paramlist;
    if (op.IsConst())
        paramlist = "const " + paramlist;
}

wxString functionName;
if ((op.GetType() & ITEM_IS_NORMALOP) != 0)
{
    functionName = op.GetName();
}
else if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
{
    functionName = "Constructor";
    type = "void ";
}
else if ((op.GetType() & ITEM_IS_DEST) != 0)
{
    functionName = "Destructor";
    type = "void ";
}

if (paramlist.empty())
    paramlist = "void";

out << (const char*)prefix.c_str()
	<< (const char*)type.c_str()
	<< (const char*)source->GetName().c_str()
	<< "_" << (const char*)functionName.c_str()
	<< "(" << (const char*)paramlist.c_str()
	<< ")" << std::endl;
out << "{" << std::endl;

int traceLevel = op.GetTraceLevel();

if (!op.IsInline() && traceLevel > 0)
{
	wxString mestr;
	if (op.IsStatic())
		mestr = "0";
	else
		mestr = "me";

	// Write the Tracing Macro
	if ((op.GetType() & ITEM_IS_NORMALOP) != 0)
	{
		out << "\tNOTIFY_CFUNCTION_CALL("
			<< mestr << ", "
			<< traceLevel << ", "
			<< "\"" << (const char*)source->GetName().c_str() << "\", "
			<< "\"" << (const char*)op.GetName().c_str() << "\", "
			<< "\"" << (const char*)paramlist.c_str() << "\", "
			<< "\"" << (const char*)type.c_str() << "\")"
			<< std::endl;
	}
	else if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
	{
		out << "\tNOTIFY_CCONSTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << (const char*)source->GetName().c_str() << "\", "
			<< "\"" << (const char*)paramlist.c_str() << "\")"
			<< std::endl;
	}
	else if ((op.GetType() & ITEM_IS_DEST) != 0)
	{
		out << "\tNOTIFY_CDESTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << (const char*)source->GetName().c_str() << "\")"
			<< std::endl;
	}
}

if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
{ // constructor
	out << InitializerList(&op);
	CodePortConnections(out);

	const AdeConstructor* pc = dynamic_cast<const AdeConstructor*>(&op);
	wxString theInitializers;
	if (pc)
		theInitializers = pc->GetInitializers();

	for (std::set<wxString>::iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
	{
		out << "\t"	<< (*it) << "_Constructor(&(me->" << (*it) << "_base)";

		wxString search = *it + "_INIT";
		search.MakeUpper();

		if (theInitializers.Find(search) != wxNOT_FOUND)
			out << "," << search;

		out << ");"	<< std::endl;
	}
}

Constraints(out,op);

out << "//[" << (const char*)CodeName.GetFullPath(wxPATH_UNIX).c_str()
    <<   "]" << std::endl;

if (theCode.IsOpened() && theCode.GetLineCount() > 0)
{
	wxString str;
	for (str = theCode.GetFirstLine(); !theCode.Eof(); str = theCode.GetNextLine())
		out << "\t" << (const char*)search4return(str,traceLevel).c_str() << std::endl;
	if (str.size())
		out << "\t" << (const char*)search4return(str,traceLevel).c_str() << std::endl;
}
else
	out << "\t// for roundtrip place your code here!" << std::endl;

out << "//[EOF]" << std::endl;

if ((op.GetType() & ITEM_IS_DEST) != 0)
{ // destructor
	for (std::set<wxString>::iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
	{
		out << "\t"
			<< (*it) << "_Destructor(&(me->" << (*it) << "_base));"
			<< std::endl;
	}
}

if (!op.IsInline() && traceLevel > 0 && type == "void ")
	out << "\tvoidRETURN;" << std::endl;

out << "}" << std::endl;
out << std::endl;
