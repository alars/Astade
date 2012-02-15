//~~ void CodeIsInStateDataElement(AdeStatechart& theStatechart, AdeState& theState) [StateChartCoderCdSys] ~~

fprintf(implementationFile, "\t%s_sm_s_%s,\n", (const char*)theStatechart.GetName().Lower().utf8_str(), (const char*)theState.GetName().Lower().utf8_str());

fprintf(specificationFile, "\t%s_SM_STATE_ID_%s,\n", (const char*)theStatechart.GetName().Upper().utf8_str(), (const char*)theState.GetName().Upper().utf8_str());
