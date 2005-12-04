wxString event = theTransition.GetTrigger();

if (!event.empty())
{
	fprintf(implementationFile,"\t\tcase ID_%s:\n",event.c_str());

	fprintf(implementationFile,"\t\tbreak;\n\n");
}
