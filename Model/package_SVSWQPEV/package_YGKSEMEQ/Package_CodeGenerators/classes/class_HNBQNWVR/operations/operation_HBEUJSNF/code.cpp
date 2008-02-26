/* vi: set tabstop=4: */

wxString prefix = "extern ";

wxString type(op.GetReturntype());
if (!type.empty())
	type += " ";

wxString postfix;
if (op.IsDeprecated())
	postfix += " __attribute__ ((deprecated))";

std::map<int,const AdeParameter*> params;
std::map<int,const AdeParameter*>::iterator it;
wxString paramlist(Paramlist(op, params, true));

if (!op.IsStatic())
{
	if (!paramlist.empty())
        paramlist = ", " + paramlist;
    paramlist = source->GetName() + "* me" + paramlist;
    if (op.IsConst())
        paramlist = "const " + paramlist;
}

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

out << (const char*)prefix.c_str()
	<< (const char*)type.c_str()
	<< (const char*)source->GetName().c_str()
    << "_"
	<< (const char*)op.GetName().c_str()
	<< "(" << (const char*)paramlist.c_str()
	<< ")" << (const char*)postfix.c_str()
	<< ";"
	<< std::endl;
out << std::endl;
