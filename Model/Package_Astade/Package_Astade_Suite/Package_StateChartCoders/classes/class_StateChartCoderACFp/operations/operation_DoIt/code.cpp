//~~ int DoIt(int argc, char* const* argv) [StateChartCoderACFp] ~~

wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));
CmdLineParser.AddParam(wxS("DIRNAME"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY);
CmdLineParser.AddParam(wxS("TARGETFILE"),  wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY);

CmdLineParser.SetLogo(wxS("StateChartCoderACF++: the \"ACF state-chart coder\"\n" COPYRIGHT));

if (CmdLineParser.Parse() != 0 || CmdLineParser.GetParamCount() != 2)
	return EXIT_FAILURE;

AdeModelElement* element = AdeModelElement::CreateNewElement(CmdLineParser.GetParam(0));
if ((element->GetType() & ITEM_TYPE_MASK) != ITEM_IS_STATECHART)
{
	std::cerr << "Error: only state charts please!" << std::endl;
	return EXIT_FAILURE;
}
myAdeStatechart = dynamic_cast<AdeStatechart*>(element);
assert(myAdeStatechart);
myAdeStatechart->SetEventType(wxS("ACF_Message"));

myFilename = CmdLineParser.GetParam(1);
wxFileName aPrologue(myFilename);
aPrologue.RemoveLastDir();
aPrologue.SetFullName(wxS("prolog.h"));

myFilename.SetExt(wxS("h"));
spec.open(myFilename.GetFullPath().utf8_str());
InsertFile(spec, aPrologue.GetFullPath());
PrintHeader(spec, myFilename.GetFullName());

wxFileName myImplname(myFilename);
myImplname.SetExt(wxS("cpp"));
impl.open(myImplname.GetFullPath().utf8_str());
aPrologue.SetExt(wxS("cpp"));
InsertFile(impl, aPrologue.GetFullPath());
PrintHeader(impl, myImplname.GetFullName());

CodeStatechart();

aPrologue.SetFullName(wxS("epilog.h"));
InsertFile(spec, aPrologue.GetFullPath());
aPrologue.SetExt(wxS("cpp"));
InsertFile(impl, aPrologue.GetFullPath());

spec.close();
impl.close();

wxDateTime theTime(myAdeStatechart->GetModificationTime());
myFilename.SetTimes(&theTime, &theTime, &theTime);
myImplname.SetTimes(&theTime, &theTime, &theTime);

return EXIT_SUCCESS;
