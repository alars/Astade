/* vi: set tabstop=4: */

wxString prefix;
if (op.IsStatic())
	prefix = "static ";
if (op.IsVirtual())
	prefix = "virtual ";
if (op.IsInline())
	prefix += "inline ";
if (op.IsExplicit())
	prefix += "explicit ";

wxString type(op.GetReturntype());
if (!type.empty())
	type += " ";

wxString postfix;
if (op.IsConst())
	postfix = " const";
if (op.IsAbstract())
	postfix += " = 0";

std::map<int,const AdeParameter*> params;
std::map<int,const AdeParameter*>::iterator it;
wxString paramlist(Paramlist(op, params, true));
out << "/** " << (const char*)op.GetDescription() << std::endl;
for (it = params.begin(); it != params.end(); ++it)
{
	out << "@param " << (const char*)(*it).second->GetName()
		<< " "       << (const char*)(*it).second->GetDescription()
		<< std::endl;
	delete (*it).second;
}
wxString ReturnDescription(op.GetReturnDescription());
if (!ReturnDescription.empty())
	out << "@return " << (const char*)ReturnDescription << std::endl;
out << "*/"   << std::endl;

out << "\t" << (const char*)prefix
	<< (const char*)type
	<< (const char*)op.GetName()
	<< "(" << (const char*)paramlist
	<< ")" << (const char*)postfix
	<< ";"
	<< std::endl;
out << std::endl;
