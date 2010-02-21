/* vi: set tabstop=4: */

target.SetExt("h");
std::ofstream out(target.GetFullPath().c_str());

wxFileName PrefixName(myAdeComponent->GetFileName());
PrefixName.SetFullName("prolog.h");
wxTextFile Gprefixtext(PrefixName.GetFullPath());
if (Gprefixtext.Exists())
	Gprefixtext.Open();
if (Gprefixtext.IsOpened() && Gprefixtext.GetLineCount() > 0)
{
	wxString str;
	for (str = Gprefixtext.GetFirstLine(); !Gprefixtext.Eof(); str = Gprefixtext.GetNextLine())
		out << (const char*)str.c_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.c_str() << std::endl;
	out << std::endl;
}

PrintHeader(out);

wxString defname(target.GetFullName());
defname.MakeUpper();
defname.Replace(".","_");

out << "#ifndef __"   << (const char*)defname.c_str() << std::endl;
out << "#  define __" << (const char*)defname.c_str() << std::endl;
out << std::endl;

out << "#ifdef __cplusplus" << std::endl;
out << "extern \"C\" {" << std::endl;
out << "#endif" << std::endl;

PrefixName = source->GetFileName();
PrefixName.SetFullName("prolog.h");
wxTextFile prefixtext(PrefixName.GetFullPath());
PrefixName.MakeRelativeTo(wxFileName::GetCwd());

if (prefixtext.Exists())
	prefixtext.Open();
if (prefixtext.IsOpened() && prefixtext.GetLineCount() > 0)
{
	out << "//****** specification prolog ******" << std::endl;
	out << "//[" << (const char*)PrefixName.GetFullPath(wxPATH_UNIX).c_str()
		<<   "]" << std::endl;
	wxString str;
	for (str = prefixtext.GetFirstLine(); !prefixtext.Eof(); str = prefixtext.GetNextLine())
		out << (const char*)str.c_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.c_str() << std::endl;
	out << "//[EOF]" << std::endl;
	out << "//**********************************" << std::endl;
	out << std::endl;
}

RelationIncludes(out, true);

wxString description(source->GetDescription());
if (!description.empty())
{
	out << "/** " << (const char*)description.c_str() << std::endl;
	out << "*/"   << std::endl;
}
out << "typedef struct" << std::endl;
out << "{" << std::endl;

if (!baseClasses.empty())
{
	out << "\t//base classes" << std::endl;
}

for (std::set<wxString>::iterator it = baseClasses.begin(); it != baseClasses.end(); it++)
{
	out << "\t"
		<< (*it) << " " << (*it) <<  "_base;"
		<< std::endl;
}

memberType(out);
memberAttribute(out, true, ITEM_IS_PUBLIC);
memberAttribute(out, true, ITEM_IS_PROTECTED);
relationAttribute(out, true);
memberAttribute(out, true, ITEM_IS_PRIVATE);

out << "} " << (const char*)source->GetName().c_str() << ";" << std::endl;
out << std::endl;

staticAttribute(out, true, ITEM_IS_PUBLIC);
operations(out, true, false, ITEM_IS_PUBLIC);

wxFileName PostfixName(source->GetFileName());
PostfixName.SetFullName("epilog.h");
wxTextFile postfixtext(PostfixName.GetFullPath());
PostfixName.MakeRelativeTo(wxFileName::GetCwd());

if (postfixtext.Exists())
	postfixtext.Open();

if (postfixtext.IsOpened() && postfixtext.GetLineCount() > 0)
{
	out << "//****** specification epilog ******" << std::endl;
	out << "//[" << (const char*)PostfixName.GetFullPath(wxPATH_UNIX).c_str()
		<<   "]" << std::endl;
	wxString str;
	for (str = postfixtext.GetFirstLine(); !postfixtext.Eof(); str = postfixtext.GetNextLine())
		out << (const char*)str.c_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.c_str() << std::endl;
	out << "//[EOF]" << std::endl;
	out << "//**********************************" << std::endl;
	out << std::endl;
}

out << "#ifdef __cplusplus" << std::endl;
out << "}" << std::endl;
out << "#endif" << std::endl << std::endl;

out << "#endif" << std::endl;

PostfixName = myAdeComponent->GetFileName();
PostfixName.SetFullName("epilog.h");
wxTextFile Gpostfixtext(PostfixName.GetFullPath());
if (Gpostfixtext.Exists())
	Gpostfixtext.Open();
if (Gpostfixtext.IsOpened() && Gpostfixtext.GetLineCount() > 0)
{
	out << std::endl;
	wxString str;
	for (str = Gpostfixtext.GetFirstLine(); !Gpostfixtext.Eof(); str = Gpostfixtext.GetNextLine())
		out << (const char*)str.c_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.c_str() << std::endl;
}

target.SetExt("h");
out.close();
wxDateTime aTime(wxDateTime::Now());
target.SetTimes(&aTime,&aTime,&aTime);
