fprintf(specificationUsrFile,"//************* actions **************************\n");

std::set<wxString> aSet = theStatechart.GetActions();

for (std::set<wxString>::iterator iter = aSet.begin(); iter!=aSet.end(); iter++)
{
	fprintf(specificationUsrFile,"extern \tvoid \t%s_impl_%s (\n", theStatechart.GetName().Lower().c_str(), (*iter).Lower().c_str());
	fprintf(specificationUsrFile,"       \t%s_SM_CTRL    \t*sm,\n", theStatechart.GetName().Upper().c_str());
	fprintf(specificationUsrFile,"       \t%s_COMMON_EVT \t*evt);\n\n", theStatechart.GetName().Upper().c_str());
}