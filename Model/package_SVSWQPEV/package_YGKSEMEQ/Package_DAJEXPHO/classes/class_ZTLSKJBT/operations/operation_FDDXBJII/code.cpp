wxString event = theTransition.GetTrigger();

if (!event.empty())
{
	fprintf(implementationFile,"\t// %s\n",theTransition.GetLabel().c_str());
	fprintf(implementationFile,"\tif ((itsID == ID_%s) && (%s(theEvent)))\n\t{\n",event.c_str(),theTransition.GetGuard().c_str());

	fprintf(implementationFile,"\t\tEnterState(theEvent);\n");
	fprintf(implementationFile,"\t\treturn true;\n");

	fprintf(implementationFile,"\t}\n\telse\n");
}
