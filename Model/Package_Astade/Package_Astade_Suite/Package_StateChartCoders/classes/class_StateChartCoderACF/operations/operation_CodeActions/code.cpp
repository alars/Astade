impl << "//************* actions **************************" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetActions();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	impl << "extern void "
		<< myAdeStatechart->GetName().c_str()
		<< "_impl_"
		<< (*iter).c_str()
		<< "(void*, "
		<< myAdeStatechart->GetEventType().c_str()
		<< "* theEvent);\n"
		<< std::endl;
