std::set<wxString> aSet = myAdeStatechart->GetGuards();
if (aSet.empty())
    return;

impl << "//************* guards **************************" << std::endl;

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	impl << "extern int "
		<< myAdeStatechart->GetName().c_str()
		<< "_impl_"
		<< (*iter).c_str()
		<< "(void*, ACF_Message* event);"
		<< std::endl;
impl << std::endl;                        
