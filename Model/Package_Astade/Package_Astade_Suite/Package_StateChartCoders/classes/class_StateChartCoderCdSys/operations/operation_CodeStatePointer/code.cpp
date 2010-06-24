//~~ void CodeStatePointer(AdeStatechart& theStatechart) [StateChartCoderCdSys] ~~
fprintf(specificationFile, "\t\t//! \\brief The pointer, holding the current state.\n");
fprintf(specificationFile, "\t\tbool ( %s::* theState )(wxEvent&);\n\n", (const char*)theStatechart.GetName().c_str());
