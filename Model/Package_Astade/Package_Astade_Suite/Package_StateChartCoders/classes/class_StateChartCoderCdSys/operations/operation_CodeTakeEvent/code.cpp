//~~ void CodeTakeEvent(AdeStatechart& theStatechart) [StateChartCoderCdSys] ~~

fprintf(specificationFile, "//! \\brief Call this function to pass an event to the state machine.\n");
fprintf(specificationFile, "//! \\Calling this function is allowed only after calling the \"Initialize\" function.\n");
fprintf(specificationFile, "//! \\param sm	The statemachine.\n");
fprintf(specificationFile, "//! \\param evt	The event to be processed.\n");
fprintf(specificationFile, "//! \\return Boolean, whether the event was \"taken\" (there was a reaction on that event).\n");

fprintf(specificationFile, "extern\tBOOL                \t%s_sm_take_event (\n", (const char*)theStatechart.GetName().Lower().utf8_str());
fprintf(specificationFile, "      \t%s_SM_CTRL          \t*sm,\n", (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(specificationFile, "      \tstruct %s_common_evt\t*evt);\n\n", (const char*)theStatechart.GetName().Lower().utf8_str());

fprintf(implementationFile, "extern\tBOOL               \t%s_sm_take_event (\n", (const char*)theStatechart.GetName().Lower().utf8_str());
fprintf(implementationFile, "      \t%s_SM_CTRL          \t*sm,\n", (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(implementationFile, "      \tstruct %s_common_evt\t*evt)\n", (const char*)theStatechart.GetName().Lower().utf8_str());
fprintf(implementationFile, "{\n");
fprintf(implementationFile, "\t// Call state function\n");
fprintf(implementationFile, "\tBOOL ret = (sm->the_state)(sm, evt);\n");

fprintf(implementationFile, "\t// Call the state enter function\n");
fprintf(implementationFile, "\t_enter_state(sm, evt);\n");

fprintf(implementationFile, "\treturn ret;\n");
fprintf(implementationFile, "}\n\n");
