wxFileName PrefixName(theStatechart.GetFileName());
PrefixName.SetFullName("epilog.cpp");
wxTextFile prefixtext(PrefixName.GetFullPath());
PrefixName.MakeRelativeTo(wxFileName::GetCwd());

if (prefixtext.Exists())
{
	prefixtext.Open();
}
 
if (prefixtext.IsOpened() && prefixtext.GetLineCount() > 0)
{
         
        fprintf(implementationFile, "/******* implementation epilog *******/\n");
        fprintf(implementationFile, "/*[ %s ]*/\n", (const char*)PrefixName.GetFullPath().c_str());

        wxString line;
        for (line = prefixtext.GetFirstLine(); !prefixtext.Eof(); line = prefixtext.GetNextLine())
        {
            fprintf(implementationFile, "%s\n", (const char*)line.c_str());
        }

        if (!line.empty())
        {
	    fprintf(implementationFile, "%s\n", (const char*)line.c_str());
        }

	fprintf(implementationFile, "/*[EOF]*/\n");
	fprintf(implementationFile, "/*************************************/\n\n");
}
else
{
        fprintf(implementationFile, "/******* No implementation epilog *******/\n\n");
}

prefixtext.Close();

PrefixName.SetFullName("epilog.h");
prefixtext.Open(PrefixName.GetFullPath());
PrefixName.MakeRelativeTo(wxFileName::GetCwd());

if (prefixtext.Exists())
{
	prefixtext.Open();
        printf("Epilog File: %s \n",  (const char*)PrefixName.GetFullPath().c_str());
}
else
{
        printf("no epilog file %s ! \n",  (const char*)PrefixName.GetFullPath().c_str());
}

 
if (prefixtext.IsOpened() && prefixtext.GetLineCount() > 0)
{
         
        fprintf(specificationFile, "/******* specification epilog *******/\n");
        fprintf(specificationFile, "/*[ %s ]*/\n", (const char*)PrefixName.GetFullPath().c_str());

        wxString line;
        for (line = prefixtext.GetFirstLine(); !prefixtext.Eof(); line = prefixtext.GetNextLine())
        {
            fprintf(specificationFile, "%s\n", (const char*)line.c_str());
        }

        if (!line.empty())
        {
	    fprintf(specificationFile, "%s\n", (const char*)line.c_str());
        }

	fprintf(specificationFile, "/*[EOF]*/\n");
	fprintf(specificationFile, "/*************************************/\n\n");
}
else
{
        fprintf(specificationFile, "/******* No specification epilog *******/\n");
}
