//~~ void doHpp() [CppGenerator] ~~

target.SetExt(wxS("h"));
std::ofstream out(target.GetFullPath().char_str());

wxFileName PrefixName(myAdeComponent->GetFileName());
PrefixName.SetFullName(wxS("prolog.h"));
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
defname.Replace(wxS("."), wxS("_"));

out << "#ifndef __"   << (const char*)defname.c_str() << std::endl;
out << "#  define __" << (const char*)defname.c_str() << std::endl;
out << std::endl;

PrefixName = source->GetFileName();
PrefixName.SetFullName(wxS("prolog.h"));
wxTextFile prefixtext(PrefixName.GetFullPath());
PrefixName.MakeRelativeTo();

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

wxString BaseClasses;
RelationIncludes(out, true, &BaseClasses);

if (!source->GetAdditionalBaseClasses().empty())
{
	if (!BaseClasses.empty())
		BaseClasses = source->GetAdditionalBaseClasses() + wxS(", ") + BaseClasses;
	else
		BaseClasses = source->GetAdditionalBaseClasses();
}
wxString description(source->GetDescription());
if (!description.empty())
{
	out << "/** " << (const char*)description.c_str() << std::endl;
	out << "*/"   << std::endl;
}

if (!source->IsManualClass())
{
	wxArrayString myNamespace(source->getNamespace());
	for (unsigned int ix = 0; ix < myNamespace.GetCount(); ++ix)
		out << "namespace "
			<< (const char*)myNamespace[ix].c_str()
			<< " {"
			<< std::endl;
    if (!source->GetTemplateString().empty())
        out << "template <" << (const char*)source->GetTemplateString().c_str() << ">" << std::endl;

    out << "class " << (const char*)source->GetName().c_str();
    if (!BaseClasses.empty())
        out << " : " << (const char*)BaseClasses.c_str();
    out << std::endl;
    out << "{" << std::endl;

    Friends(out);

    out << "public:" << std::endl;

    declarePorts(out);

    memberType(out);
    staticAttribute(out, true, ITEM_IS_PUBLIC);
    memberAttribute(out, true, ITEM_IS_PUBLIC);
    operations(out, true, false, ITEM_IS_PUBLIC);
    out << std::endl;

    out << "protected:" << std::endl;
    staticAttribute(out, true, ITEM_IS_PROTECTED);
    memberAttribute(out, true, ITEM_IS_PROTECTED);
    relationAttribute(out, true);
    operations(out, true, false, ITEM_IS_PROTECTED);
    out << std::endl;

    out << "private:" << std::endl;
    staticAttribute(out, true, ITEM_IS_PRIVATE);
    memberAttribute(out, true, ITEM_IS_PRIVATE);
    operations(out, true, false, ITEM_IS_PRIVATE);

    if (inheritsFromStatechart) // this is tested during relation coding
    {
        out << "#ifdef ASTADE_STATECHART_SPECIFICATION" << std::endl;
        out << "\tASTADE_STATECHART_SPECIFICATION" << std::endl;
        out << "#endif" << std::endl;
        out << std::endl;
    }

    out << "};" << std::endl;
	for (unsigned int ix = myNamespace.GetCount(); ix-- > 0; )
	    out << "} // namespace "
			<< (const char*)myNamespace[ix].c_str()
			<< std::endl;
    out << std::endl;

    operations(out, false, true, ITEM_IS_PUBLIC);
    operations(out, false, true, ITEM_IS_PROTECTED);
    operations(out, false, true, ITEM_IS_PRIVATE);
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
		out << (const char*)str.c_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.c_str() << std::endl;
}

target.SetExt(wxS("h"));
out.close();

wxDateTime theTime(source->GetModificationTime());
target.SetTimes(&theTime, &theTime, &theTime);
