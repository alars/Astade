//~~ void specOperation(std::ofstream& out, const AdeOperationBase& op) [CppGenerator] ~~

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
out << "/** " << op.GetDescription() << std::endl;

if (op.IsDeprecated())
	out << "@deprecated " << op.GetDeprecatedDesc() << std::endl;

for (it = params.begin(); it != params.end(); ++it)
{
	out << "@param " << (*it).second->GetName()
		<< " "       << (*it).second->GetDescription()
		<< std::endl;
	delete (*it).second;
}
wxString ReturnDescription(op.GetReturnDescription());
if (!ReturnDescription.empty())
	out << "@return " << ReturnDescription << std::endl;
out << "*/"   << std::endl;

out << "\t" << prefix
	<< type
	<< op.GetName()
	<< "(" << paramlist
	<< ")" << postfix
	<< ";"
	<< std::endl;
out << std::endl;
