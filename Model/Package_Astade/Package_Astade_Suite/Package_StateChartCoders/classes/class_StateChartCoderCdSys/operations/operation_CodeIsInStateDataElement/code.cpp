//~~ void CodeIsInStateDataElement(AdeStatechart& theStatechart, AdeState& theState) [StateChartCoderCdSys] ~~
fprintf(implementationFile, "\t%s_sm_s_%s,\n", (const char*)theStatechart.GetName().Lower().c_str(), (const char*)theState.GetName().Lower().c_str());

fprintf(specificationFile, "\t%s_SM_STATE_ID_%s,\n", (const char*)theStatechart.GetName().Upper().c_str(), (const char*)theState.GetName().Upper().c_str());
