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

std::map<int, const AdeParameter*> params;
std::map<int, const AdeParameter*>::iterator it;
wxString paramlist(Paramlist(op, params, true));
out << "/** @brief " << op.GetDescription().utf8_str() << std::endl;

if (op.IsDeprecated())
	out << "@deprecated " << op.GetDeprecatedDesc().utf8_str() << std::endl;

for (it = params.begin(); it != params.end(); ++it)
{
	out << "@param " << it->second->GetName().utf8_str()
		<< " "       << it->second->GetDescription().utf8_str()
		<< std::endl;
	delete it->second;
}
wxString ReturnDescription(op.GetReturnDescription());
if (!ReturnDescription.empty())
	out << "@return " << ReturnDescription.utf8_str() << std::endl;

Constraints_comment(out, op);

out << "*/"   << std::endl;

out << "\t" << prefix.utf8_str()
	<< type.utf8_str()
	<< op.GetName().utf8_str()
	<< "(" << paramlist.utf8_str()
	<< ")" << postfix.utf8_str()
	<< ";"
	<< std::endl;
out << std::endl;
