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

wxString Template(source->GetTemplateString());
if (!Template.empty())
	out << "template <"
		<< (const char*)source->GetTemplateString().c_str()
		<< "> ";

out << (const char*)prefix.c_str()
	<< (const char*)type.c_str()
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
	}
	else if (typeid(op) == typeid(AdeDestructor))
	{
		out << "\tNOTIFY_DESTRUCTOR("
			<< traceLevel << ", "
			<< "\"" << (const char*)source->GetName().c_str() << "\")"
			<< std::endl;
	}
}

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
