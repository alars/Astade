//~~ void doH() [CGenerator] ~~

target.SetExt(wxS("h"));
std::ofstream out(target.GetFullPath().utf8_str());

wxFileName PrefixName(myAdeComponent->GetFileName());
PrefixName.SetFullName(wxS("prolog.h"));
wxTextFile Gprefixtext(PrefixName.GetFullPath());
if (Gprefixtext.Exists())
	Gprefixtext.Open();
if (Gprefixtext.IsOpened() && Gprefixtext.GetLineCount() > 0)
{
	wxString str;
	for (str = Gprefixtext.GetFirstLine(); !Gprefixtext.Eof(); str = Gprefixtext.GetNextLine())
		out << (const char*)str.utf8_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.utf8_str() << std::endl;
	out << std::endl;
}

PrintHeader(out);

wxString defname(target.GetFullName());
defname.MakeUpper();
defname.Replace(wxS("."), wxS("_"));

out << "#ifndef __"   << (const char*)defname.utf8_str() << std::endl;
out << "#  define __" << (const char*)defname.utf8_str() << std::endl;
out << std::endl;

out << "#ifdef __cplusplus" << std::endl;
out << "extern \"C\" {" << std::endl;
out << "#endif" << std::endl;

PrefixName = source->GetFileName();
PrefixName.SetFullName(wxS("prolog.h"));
wxTextFile prefixtext(PrefixName.GetFullPath());
PrefixName.MakeRelativeTo();

if (prefixtext.Exists())
	prefixtext.Open();
if (prefixtext.IsOpened() && prefixtext.GetLineCount() > 0)
{
	out << "//****** specification prolog ******" << std::endl;
	out << "//[" << (const char*)PrefixName.GetFullPath(wxPATH_UNIX).utf8_str()
		<<   "]" << std::endl;
	wxString str;
	for (str = prefixtext.GetFirstLine(); !prefixtext.Eof(); str = prefixtext.GetNextLine())
		out << (const char*)str.utf8_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.utf8_str() << std::endl;
	out << "//[EOF]" << std::endl;
	out << "//**********************************" << std::endl;
	out << std::endl;
}

RelationIncludes(out, true);

wxString description(source->GetDescription());
if (!description.empty())
{
	out << "/** " << (const char*)description.utf8_str() << std::endl;
	out << "*/"   << std::endl;
}

if( !source->IsManualClass() )
{
    out << "typedef struct " << (const char*)source->GetName().utf8_str() << std::endl;
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

    declarePorts(out);
    
    memberType(out);
    memberAttribute(out, true, ITEM_IS_PUBLIC);
    memberAttribute(out, true, ITEM_IS_PROTECTED);
    relationAttribute(out, true);
    memberAttribute(out, true, ITEM_IS_PRIVATE);

    out << "} " << (const char*)source->GetName().utf8_str() << ";" << std::endl;
    out << std::endl;

    staticAttribute(out, true, ITEM_IS_PUBLIC);
    operations(out, true, false, ITEM_IS_PUBLIC);
    operations(out, false, true, ITEM_IS_PUBLIC);
}

wxFileName PostfixName(source->GetFileName());
PostfixName.SetFullName(wxS("epilog.h"));
wxTextFile postfixtext(PostfixName.GetFullPath());
PostfixName.MakeRelativeTo();

if (postfixtext.Exists())
	postfixtext.Open();

if (postfixtext.IsOpened() && postfixtext.GetLineCount() > 0)
{
	out << "//****** specification epilog ******" << std::endl;
	out << "//[" << (const char*)PostfixName.GetFullPath(wxPATH_UNIX).utf8_str()
		<<   "]" << std::endl;
	wxString str;
	for (str = postfixtext.GetFirstLine(); !postfixtext.Eof(); str = postfixtext.GetNextLine())
		out << (const char*)str.utf8_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.utf8_str() << std::endl;
	out << "//[EOF]" << std::endl;
	out << "//**********************************" << std::endl;
	out << std::endl;
}

out << "#ifdef __cplusplus" << std::endl;
out << "}" << std::endl;
out << "#endif" << std::endl << std::endl;

out << "#endif" << std::endl;

PostfixName = myAdeComponent->GetFileName();
PostfixName.SetFullName(wxS("epilog.h"));
wxTextFile Gpostfixtext(PostfixName.GetFullPath());
if (Gpostfixtext.Exists())
	Gpostfixtext.Open();
if (Gpostfixtext.IsOpened() && Gpostfixtext.GetLineCount() > 0)
{
	out << std::endl;
	wxString str;
	for (str = Gpostfixtext.GetFirstLine(); !Gpostfixtext.Eof(); str = Gpostfixtext.GetNextLine())
		out << (const char*)str.utf8_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.utf8_str() << std::endl;
}

target.SetExt(wxS("h"));
out.close();

wxDateTime theTime(source->GetModificationTime());
target.SetTimes(&theTime, &theTime, &theTime);
