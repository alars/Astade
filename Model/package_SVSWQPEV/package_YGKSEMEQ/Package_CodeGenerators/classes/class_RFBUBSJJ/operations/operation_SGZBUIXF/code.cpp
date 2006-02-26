/* vi: set tabstop=4: */

wxString Prefix;
if (isInline)
	Prefix = "inline ";
wxString Postfix;
if (isConst)
	Postfix = " const";

if (source->GetName() == name)
{
	// Constructor:
	out << Prefix
		<< source->GetName()
		<< "::" << name
		<< "("  << Paramlist(filename)
		<< ")"  << InitializerList(filename)
		<< std::endl;
	out << "{"  << std::endl;
}
else
{
	out << Prefix
		<< type
		<< " "  << source->GetName()
		<< "::" << name
		<< "("  << Paramlist(filename)
		<< ")"  << Postfix
		<< std::endl;
	out << "{"  << std::endl;
}

if (theCode->Exists())
	theCode->Open();
if (theCode->IsOpened() && theCode->GetLineCount() > 0)
{
	out << "//[" << theCode->GetName() << "]" << std::endl;
	wxString str;
	for (str = theCode->GetFirstLine(); !theCode->Eof(); str = theCode->GetNextLine())
		out << "\t" << str << std::endl;
	if (str.size())
		out << "\t" << str << std::endl;
	out << "//[EOF]" << std::endl;
}    
out << "};" << std::endl;
out << std::endl;
