//~~ void specOperation(std::ofstream& out, const AdeOperationBase& op) [CppGenerator] ~~
/* vi: set tabstop=4: */

wxString prefix;
if (op.IsStatic())
	prefix = wxS("static ");
if (op.IsVirtual())
	prefix = wxS("virtual ");
if (op.IsInline())
	prefix += wxS("inline ");
if (op.IsExplicit())
	prefix += wxS("explicit ");

wxString type(op.GetReturntype());
if (!type.empty())
	type += wxS(" ");

wxString postfix;
if (op.IsConst())
	postfix = wxS(" const");
if (op.IsAbstract())
	postfix += wxS(" = 0");
if (op.IsDeprecated())
	postfix += wxS(" __attribute__ ((deprecated))");

std::map<int,const AdeParameter*> params;
std::map<int,const AdeParameter*>::iterator it;
wxString paramlist(Paramlist(op, params, true));
out << "/** " << (const char*)op.GetDescription().c_str() << std::endl;

if (op.IsDeprecated())
	out << "@deprecated " << (const char*)op.GetDeprecatedDesc().c_str() << std::endl;

for (it = params.begin(); it != params.end(); ++it)
{
	out << "@param " << (const char*)(*it).second->GetName().c_str()
		<< " "       << (const char*)(*it).second->GetDescription().c_str()
		<< std::endl;
	delete (*it).second;
}
wxString ReturnDescription(op.GetReturnDescription());
if (!ReturnDescription.empty())
	out << "@return " << (const char*)ReturnDescription.c_str() << std::endl;
out << "*/"   << std::endl;

out << "\t" << (const char*)prefix.c_str()
	<< (const char*)type.c_str()
	<< (const char*)op.GetName().c_str()
	<< "(" << (const char*)paramlist.c_str()
	<< ")" << (const char*)postfix.c_str()
	<< ";"
	<< std::endl;
out << std::endl;
