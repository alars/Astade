//~~ void specOperation(std::ofstream& out, const AdeOperationBase& op, bool doStatic) [CGenerator] ~~

wxString prefix;
if (doStatic)
    prefix = wxS("static ");
if (op.IsInline())
	prefix = wxS("inline ");	// "static inline" ==> "inline"

wxString type(op.GetReturntype());
if (!type.empty())
	type += wxS(" ");

wxString postfix;
if (op.IsDeprecated())
	postfix += wxS(" __attribute__ ((deprecated))");

std::map<int, const AdeParameter*> params;
std::map<int, const AdeParameter*>::iterator it;
wxString paramlist(Paramlist(op, params, true));

if (!op.IsStatic())
{
	if (!paramlist.empty())
        paramlist = wxS(", ") + paramlist;
    paramlist = source->GetName() + wxS("* me") + paramlist;
    if (op.IsConst())
        paramlist = wxS("const ") + paramlist;
}

out << "/** " << (const char*)op.GetDescription().utf8_str() << std::endl;

if (op.IsDeprecated())
	out << "@deprecated " << (const char*)op.GetDeprecatedDesc().utf8_str() << std::endl;

for (it = params.begin(); it != params.end(); ++it)
{
	out << "@param " << (const char*)(*it).second->GetName().utf8_str()
		<< " "       << (const char*)(*it).second->GetDescription().utf8_str()
		<< std::endl;
	delete (*it).second;
}
wxString ReturnDescription(op.GetReturnDescription());
if (!ReturnDescription.empty())
	out << "@return " << (const char*)ReturnDescription.utf8_str() << std::endl;
out << "*/"   << std::endl;

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

out << (const char*)prefix.utf8_str()
	<< (const char*)type.utf8_str()
	<< (const char*)source->GetName().utf8_str()
    << "_"
	<< (const char*)functionName.utf8_str()
	<< "(" << (const char*)paramlist.utf8_str()
	<< ")" << (const char*)postfix.utf8_str()
	<< ";"
	<< std::endl;
out << std::endl;
