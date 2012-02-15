//~~ void CodeEnterFunction(AdeStatechart& theStatechart) [StateChartCoderCdSys] ~~

// fprintf(specificationFile, "\t\t//! \\brief This function calls the current enter Function until a stable state is reached.\n");
// fprintf(specificationFile, "\t\t//! \\param theEvent	The event, passed to the actions and guards.\n");
// fprintf(specificationFile, "\t\tvoid EnterState(wxEvent& theEvent);\n\n");

// fprintf(implementationFile, "void %s::EnterState(wxEvent& theEvent)\n{\n", (const char*)theStatechart.GetName().utf8_str());
// fprintf(implementationFile, "\twhile(nextState)\n\t\t(this->*nextState)(theEvent);\n");
// fprintf(implementationFile, "}\n\n");

fprintf(implementationFile, "//! \\brief This function calls the current enter Function until a stable state is reached.\n");
fprintf(implementationFile, "//! \\param theEvent	The event, passed to the actions and guards.\n");
fprintf(implementationFile, "static\tvoid \t\t _enter_state (\n");
fprintf(implementationFile, "      \t%s_SM_CTRL   \t*sm,\n", (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(implementationFile, "      \t%s_COMMON_EVT\t*evt)\n", (const char*)theStatechart.GetName().Upper().utf8_str());
fprintf(implementationFile, "{\n");
fprintf(implementationFile, "\twhile(sm->next_state)\n");
fprintf(implementationFile, "\t{\n");
fprintf(implementationFile, "\t\t(sm->next_state)(sm, evt);\n");
fprintf(implementationFile, "\t}\n");
fprintf(implementationFile, "}\n\n");
