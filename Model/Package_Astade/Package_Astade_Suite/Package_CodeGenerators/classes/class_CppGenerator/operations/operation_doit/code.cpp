//~~ int doit(int argc, char* const* argv) [CppGenerator] ~~

wxConfigBase::Set(new wxFileConfig(wxS("Astade.ini")));
wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));

CmdLineParser.AddParam(wxS("class_dir"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY);
CmdLineParser.AddParam(wxS("target"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL);
CmdLineParser.AddParam(wxS("component"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL);

CmdLineParser.SetLogo(wxS("CppGenerator: the \"C++ code generator\"\n" COPYRIGHT));

if (CmdLineParser.Parse() == 0)
{
	wxFileName base(CmdLineParser.GetParam(0));
	base.SetFullName(wxS("ModelNode.ini"));
	AdeModelElement* element = AdeModelElement::CreateNewElement(base);
	if ((element->GetType() & ITEM_TYPE_MASK) != ITEM_IS_CLASS)
	{
		CmdLineParser.Usage();
		return EXIT_FAILURE;
	}
	source = dynamic_cast<AdeClass*>(element);
	assert(source);
	if (CmdLineParser.GetParamCount() > 1)
		target = CmdLineParser.GetParam(1);
	else
		target = source->GetSpecFileName();
	theClassName = source->GetLabel();
	if (CmdLineParser.GetParamCount() > 2)
		myAdeComponent = new AdeComponent(CmdLineParser.GetParam(2));
	else
		myAdeComponent = new AdeComponent(wxConfigBase::Get()->Read(wxS("TreeView/ActiveComponent")));
	if (!source->IsInComponent(*myAdeComponent))
		return EXIT_FAILURE;
	theAdditionalBaseClasses = source->GetAdditionalBaseClasses();

	doHpp();
	doCpp();
 	return EXIT_SUCCESS;
}
return EXIT_FAILURE;
