//~~ void CodeStateFunctionDescription(AdeStatechart& theStatechart, AdeState& theState) [StateChartCoderCdSys] ~~

fprintf(implementationFile, "\n/*! \\brief The function of %s. \n", (const char*)theState.GetName().utf8_str());
fprintf(implementationFile, "   %s\n", (const char*)theState.GetDescription().utf8_str());
fprintf(implementationFile, "*/\n");
