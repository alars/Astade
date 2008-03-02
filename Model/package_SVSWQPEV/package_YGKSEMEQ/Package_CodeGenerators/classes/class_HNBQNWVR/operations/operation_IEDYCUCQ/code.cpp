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
if (typeid(op) == typeid(AdeOperation))
    functionName = op.GetName();
else if (typeid(op) == typeid(AdeConstructor))
{
    functionName = "Constructor";
    type = "void ";
}
else if (typeid(op) == typeid(AdeDestructor))
{
    functionName = "Destructor";
    type = "void ";
}

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
	if (typeid(op) == typeid(AdeOperation))
	{
		out << "\tNOTIFY_FUNCTION_CALL("
			<< traceLevel << ", "
			<< "\"" << (const char*)source->GetName().c_str() << "\", "
			<< "\"" << (const char*)op.GetName().c_str() << "\", "
			<< "\"" << (const char*)paramlist.c_str() << "\", "
			<< "\"" << (const char*)type.c_str() << "\")"
			<< std::endl;
	}
	else if (typeid(op) == typeid(AdeConstructor))
	{
		out << "\tNOTIFY_CONSTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << (const char*)source->GetName().c_str() << "\", "
			<< "\"" << (const char*)paramlist.c_str() << "\")"
			<< std::endl;
        out << InitializerList(&op);
	}
	else if (typeid(op) == typeid(AdeDestructor))
	{
		out << "\tNOTIFY_DESTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << (const char*)source->GetName().c_str() << "\")"
			<< std::endl;
	}
}

if (theCode.IsOpened() && theCode.GetLineCount() > 0)
{
	out << "//[" << (const char*)CodeName.GetFullPath().c_str()
		<<   "]" << std::endl;
	wxString str;
	for (str = theCode.GetFirstLine(); !theCode.Eof(); str = theCode.GetNextLine())
		out << "\t" << (const char*)str.c_str() << std::endl;
	if (str.size())
		out << "\t" << (const char*)str.c_str() << std::endl;
	out << "//[EOF]" << std::endl;
}

if (type=="void ")
    out << "\tvoidRETURN;" << std::endl;

out << "};" << std::endl;
out << std::endl;
