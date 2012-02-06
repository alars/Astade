//~~ void doC() [CGenerator] ~~

target.SetExt(wxS("c"));
std::ofstream out(target.GetFullPath().utf8_str());

wxFileName PrefixName(myAdeComponent->GetFileName());
PrefixName.SetFullName(wxS("prolog.cpp"));
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

PrefixName = source->GetFileName();
PrefixName.SetFullName(wxS("prolog.c"));

// This is for backward compatibility. In the past, C Classes uses "prolog.cpp" as action code
if (!PrefixName.FileExists())
    PrefixName.SetFullName(wxS("prolog.cpp"));

wxTextFile prefixtext(PrefixName.GetFullPath());
PrefixName.MakeRelativeTo();

if (prefixtext.Exists())
	prefixtext.Open();
if (prefixtext.IsOpened() && prefixtext.GetLineCount() > 0)
{
	wxString str;
	out << "//****** implementation prolog ******" << std::endl;
	out << "//[" << (const char*)PrefixName.GetFullPath(wxPATH_UNIX).utf8_str()
		<<   "]" << std::endl;
	for (str = prefixtext.GetFirstLine(); !prefixtext.Eof(); str = prefixtext.GetNextLine())
		out << (const char*)str.utf8_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.utf8_str() << std::endl;
	out << "//[EOF]" << std::endl;
	out << "//***********************************" << std::endl;
	out << std::endl;
}

target.SetExt(wxS("h"));
out << "#include \"" << (const char*)target.GetFullName().utf8_str();
out << "\"\t // own header" << std::endl;
out << std::endl;

RelationIncludes(out, false);

out << "//****** Trace Macros ***************" << std::endl;
out << "#ifndef NOTIFY_CCONSTRUCTOR" << std::endl;
out << "#  define NOTIFY_CCONSTRUCTOR(a,b,c)" << std::endl;
out << "#endif" << std::endl;

out << "#ifndef NOTIFY_CDESTRUCTOR" << std::endl;
out << "#  define NOTIFY_CDESTRUCTOR(a,b)" << std::endl;
out << "#endif" << std::endl;

out << "#ifndef NOTIFY_CFUNCTION_CALL" << std::endl;
out << "#  define NOTIFY_CFUNCTION_CALL(a,b,c,d,e,f)" << std::endl;
out << "#endif" << std::endl;

out << "#ifndef CRETURN" << std::endl;
out << "#  define CRETURN(a) return (a)" << std::endl;
out << "#endif" << std::endl;

out << "#ifndef voidRETURN" << std::endl;
out << "#  define voidRETURN return" << std::endl;
out << "#endif" << std::endl << std::endl;

out << "#ifndef LOG" << std::endl;
out << "#  define LOG(...)" << std::endl;
out << "#endif" << std::endl << std::endl;

if( !source->IsManualClass() )
{
    staticAttribute(out, true, ITEM_IS_PROTECTED);
    staticAttribute(out, true, ITEM_IS_PRIVATE);
    operations(out, false, true, ITEM_IS_PROTECTED);
    operations(out, false, true, ITEM_IS_PRIVATE);
    operations(out, true, false, ITEM_IS_PROTECTED);
    operations(out, true, false, ITEM_IS_PRIVATE);

    staticAttribute(out, false, ITEM_IS_PUBLIC);
    staticAttribute(out, false, ITEM_IS_PROTECTED);
    staticAttribute(out, false, ITEM_IS_PRIVATE);
    relationAttribute(out, false);

    operations(out, false, false, ITEM_IS_PUBLIC);
    operations(out, false, false, ITEM_IS_PROTECTED);
    operations(out, false, false, ITEM_IS_PRIVATE);
}

wxFileName PostfixName(source->GetFileName());
PostfixName.SetFullName(wxS("epilog.c"));

// This is for backward compatibility. In the past, C Classes uses "epilog.cpp" as action code
if (!PrefixName.FileExists())
    PrefixName.SetFullName(wxS("epilog.cpp"));

wxTextFile postfixtext(PostfixName.GetFullPath());
PostfixName.MakeRelativeTo();

if (!hasConstructor)
    CodePortConnectionWarning(out);

if (postfixtext.Exists())
	postfixtext.Open();
if (postfixtext.IsOpened() && postfixtext.GetLineCount() > 0)
{
	out << "//****** implementation epilog ******" << std::endl;
	out << "//[" << (const char*)PostfixName.GetFullPath(wxPATH_UNIX).utf8_str()
		<<   "]" << std::endl;
	wxString str;
	for (str = postfixtext.GetFirstLine(); !postfixtext.Eof(); str = postfixtext.GetNextLine())
		out << (const char*)str.utf8_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.utf8_str() << std::endl;
	out << "//[EOF]" << std::endl;
	out << "//***********************************" << std::endl;
}

PostfixName = myAdeComponent->GetFileName();
PostfixName.SetFullName(wxS("epilog.cpp"));
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

target.SetExt(wxS("c"));
out.close();

wxDateTime theTime(source->GetCodeModificationTime());
target.SetTimes(&theTime, &theTime, &theTime);
