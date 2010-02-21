std::set<wxString> aSet = myAdeStatechart->GetTrigger();
if (aSet.empty())
    return;

events << "// event definitions:" << std::endl;
impl << "//************* events ***************************" << std::endl;

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
{
	if ((*iter) != "ACF_timeout")
		events << "const char* "
			<< (*iter).c_str()
			<< " = \""
			<< (*iter).c_str()
			<< "\";"
			<< std::endl;
	impl << "extern const char* "
		<< (*iter).c_str()
		<< ";"
		<< std::endl;
}
impl << std::endl;
