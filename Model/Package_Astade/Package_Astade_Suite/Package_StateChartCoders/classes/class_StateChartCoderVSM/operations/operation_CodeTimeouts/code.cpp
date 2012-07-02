//~~ void CodeTimeouts() [StateChartCoderVSM] ~~

spec << "\t//************* timeouts **************************" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetTimeouts();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	spec << "\tunsigned int "
		<< iter->utf8_str()
		<< ";"
		<< std::endl;
