#if 0
typedef enum ifsw_sm_evtid
{
	IFSW_SM_EVTID_TIMEOUT,
   IFSW_SM_EVTID_MANUAL_IF_SET,
   IFSW_SM_EVTID_DATA,
   IFSW_SM_EVTID_CON_IND_BT,
   IFSW_SM_EVTID_CON_IND_LPD,
   IFSW_SM_EVTID_CON_IND_USB,
   IFSW_SM_EVTID_DISCON_IND_BT,
   IFSW_SM_EVTID_DISCON_IND_LPD,
   IFSW_SM_EVTID_RE_INIT_BT,
   IFSW_SM_EVTID_MODE_SET

} IFSW_SM_EVTID;
#endif

std::set<wxString> aSet = theStatechart.GetTrigger();

fprintf(specificationFile, "typedef enum %s_sm_evtid \n{\n", (const char*)theStatechart.GetName().Lower().c_str());

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	fprintf(specificationFile, "\t%s_SM_EVTID_%s,\n", (const char*)theStatechart.GetName().Upper().c_str(), (const char*)(*iter).c_str());

fprintf(specificationFile, "\n\t%s_SM_EVTID_LAST_ELEMENT\n", (const char*)theStatechart.GetName().Upper().c_str());
fprintf(specificationFile, "} %s_SM_EVTID;\n\n", (const char*)theStatechart.GetName().Upper().c_str());
