//~~ void CodeStateFunctionPrototype(AdeStatechart& theStatechart, AdeState& theState) [StateChartCoderCdSys] ~~

fprintf(implementationFile, "static\tBOOL\t%s_sm_s_%s (\n", (const char*)theStatechart.GetName().Lower().utf8_str(), (const char*)theState.GetName().Lower().utf8_str());
fprintf(implementationFile, "\t%s_SM_CTRL   \t*sm,\n", (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(implementationFile, "\t%s_COMMON_EVT\t*evt)", (const char*)theStatechart.GetName().Upper().utf8_str());
