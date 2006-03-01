/* vi: set tabstop=4: */

wxString prefix;
if (op.IsStatic())
	prefix = "static ";
if (op.IsVirtual())
	prefix = "virtual ";
if (op.IsInline())
	prefix += "inline ";

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
out << "/** " << op.GetDescription() << std::endl;
for (it = params.begin(); it != params.end(); ++it)
{
	out << "@param " << (*it).second->GetName()
		<< " "       << (*it).second->GetDescription()
		<< std::endl;
	delete (*it).second;
}
out << "*/"   << std::endl;

out << "\t" << prefix
	<< type
	<< op.GetName()
	<< "(" << paramlist
	<< ")" << postfix
	<< ";"
	<< std::endl;
