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

if (!op.IsInline() && !op.IsStatic() && traceLevel > 0)
{
	// Write the Tracing Macro
	if ((op.GetType() & ITEM_IS_NORMALOP) != 0)
	{
		out << "\tNOTIFY_FUNCTION_CALL("
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
	}
	else if ((op.GetType() & ITEM_IS_DEST) != 0)
	{
		out << "\tNOTIFY_DESTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << (const char*)source->GetName().c_str() << "\")"
			<< std::endl;
	}
}

if ((op.GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
{ // constructor
	const AdeConstructor* pc = dynamic_cast<const AdeConstructor*>(&op);
	wxString theInitializers;
	if (pc)
	{
		theInitializers = pc->GetInitializers();
		out << theInitializers << std::endl;
	}

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

out << "//[" << (const char*)CodeName.GetFullPath().c_str()
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

if ((op.GetType() & ITEM_IS_DEST) != 0)
{ // destructor
	for (std::set<wxString>::iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
	{
		out << "\t"
			<< (*it) << "_Destructor(&(me->" << (*it) << "_base));"
			<< std::endl;
	}
}


if (type=="void ")
    out << "\tvoidRETURN;" << std::endl;

out << "}" << std::endl;
out << std::endl;
