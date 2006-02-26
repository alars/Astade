/* vi: set tabstop=4: */

wxString Prefix;
if (isStatic)
	Prefix = "static ";
if (isVirtual)
	Prefix = "virtual ";
if (isInline)
	Prefix += "inline ";
wxString Postfix;
if (isConst)
	Postfix = " const";
if (isAbstract)
	Postfix += " = 0";

if (type.empty())
{
	out << "\t" << Prefix
		<< name
		<< "("  << Paramlist(filename)
		<< ")"  << Postfix
		<< ";"
		<< std::endl;
}
else
{
	out << "\t" << Prefix
		<< type
		<< " " << name
		<< "(" << Paramlist(filename)
		<< ")" << Postfix
		<< ";"
		<< std::endl;
}
