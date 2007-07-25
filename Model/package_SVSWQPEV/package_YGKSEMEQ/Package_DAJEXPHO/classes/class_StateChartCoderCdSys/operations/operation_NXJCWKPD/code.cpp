wxFileName PrefixName(theStatechart.GetFileName());
PrefixName.SetFullName("prolog.cpp");
wxTextFile prefixtext(PrefixName.GetFullPath());
PrefixName.MakeRelativeTo(wxFileName::GetCwd());

if (prefixtext.Exists())
{
	prefixtext.Open();
        printf("Prolog File: %s \n", (const char*)PrefixName.GetFullPath().c_str());
}
else
{
        printf("no Prolog file %s ! \n", (const char*)PrefixName.GetFullPath().c_str());
}

 
if (prefixtext.IsOpened() && prefixtext.GetLineCount() > 0)
{
         
        fprintf(implementationFile, "/******* implementation prolog *******/\n");
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
        fprintf(specificationFile, "/******* No implementation prolog *******/\n\n");
}

prefixtext.Close();

PrefixName.SetFullName("prolog.h");
prefixtext.Open(PrefixName.GetFullPath());
PrefixName.MakeRelativeTo(wxFileName::GetCwd());

if (prefixtext.Exists())
{
	prefixtext.Open();
        printf("Prolog File: %s \n",  (const char*)PrefixName.GetFullPath().c_str());
}
else
{
        printf("no Prolog file %s ! \n", (const char*)PrefixName.GetFullPath().c_str());
}

 
if (prefixtext.IsOpened() && prefixtext.GetLineCount() > 0)
{
         
        fprintf(specificationFile, "/******* specification prolog *******/\n");
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
        fprintf(specificationFile, "/******* No specification prolog *******/\n\n");
}