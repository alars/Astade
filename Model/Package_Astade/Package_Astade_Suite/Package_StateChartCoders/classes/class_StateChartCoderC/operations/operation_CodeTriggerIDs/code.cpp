//~~ void CodeTriggerIDs() [StateChartCoderC] ~~

spec << "typedef enum" << std::endl;
spec << "{" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetTrigger();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	spec << "\tID_"
		<< iter->utf8_str()
		<< ","
		<< std::endl;

spec << "} "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_eventIDs;"
	<< std::endl;
