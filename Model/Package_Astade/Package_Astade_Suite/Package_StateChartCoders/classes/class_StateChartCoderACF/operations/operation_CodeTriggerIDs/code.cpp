std::set<wxString> aSet = myAdeStatechart->GetTrigger();
if (aSet.empty())
    return;

impl << "//************* events ***************************" << std::endl;

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
{
	impl << "extern const char* "
		<< (*iter).c_str()
		<< ";"
		<< std::endl;
}
impl << std::endl;
