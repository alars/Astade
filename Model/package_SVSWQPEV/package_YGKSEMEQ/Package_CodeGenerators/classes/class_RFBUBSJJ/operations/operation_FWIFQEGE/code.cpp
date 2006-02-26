/* vi: set tabstop=4: */
wxConfigBase::Set(new wxFileConfig("Astade.ini"));
wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));

CmdLineParser.AddParam("class_dir", wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY);
CmdLineParser.AddParam("target", wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL);

CmdLineParser.SetLogo("CppGenerator: the \"C++ code generator\"\n" COPYRIGHT);

if (CmdLineParser.Parse() == 0)
{
	wxFileName base(CmdLineParser.GetParam(0));
	base.SetFullName("ModelNode.ini");
	AdeModelElement* element = AdeModelElement::CreateNewElement(base);
	if ((element->GetType() & ITEM_TYPE_MASK) != ITEM_IS_CLASS)
	{
		CmdLineParser.Usage();
		return EXIT_FAILURE;
	}
	source = dynamic_cast<AdeClass*>(element);
	assert(source);
	if (!source->GetIsInActiveComponent())
		return EXIT_FAILURE;
	if (CmdLineParser.GetParamCount() > 1)
		target = CmdLineParser.GetParam(1);
	else
		target = source->GetSpecFileName();
	theClassName = source->GetLabel();
	theAdditionalBaseClasses = source->GetAdditionalBaseClasses();
	wxDateTime now;
	now.SetToCurrent();
	now.MakeTimezone(wxDateTime::UTC);
	GenerationTime = now.FormatISODate() + " " + now.FormatISOTime() + " UTC";
	doHpp();
	doCpp();
	return EXIT_SUCCESS;
}
return EXIT_FAILURE;
