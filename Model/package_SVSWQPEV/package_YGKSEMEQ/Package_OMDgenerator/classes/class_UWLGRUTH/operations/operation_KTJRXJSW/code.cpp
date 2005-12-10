wxFileName path = pe->GetFileName();
if ((pe->GetType() & 0x0ff00000) == ITEM_IS_CLASS)
{
	wxString prename(parent);
	if (!parent.IsEmpty())
		prename = prename + ":" + pe->GetName();
	else
		prename = pe->GetName();
	wxString nodename(path.GetDirs()[path.GetDirCount()-1]);
	nodelist.insert(nodename);
	for (int i = 0; i < depth; ++i)
		putchar('\t');
	printf("%s [shape=record, label=\"{%s||}\", style=filled, fillcolor=grey95, color=black];\n",
		path.GetDirs()[path.GetDirCount()-1].c_str(),
		prename.c_str());

	AdeDirectoryElement de(path);
	for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
	{
		AdeModelElement* pme = eit.CreateNewElement();
		ListNodes(depth, prename, pme);
		delete pme;
	}
}
else if ((pe->GetType() & 0x0ff00000) == ITEM_IS_CLASSES)
{
	AdeDirectoryElement de(path);
	for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
	{
		AdeModelElement* pme = eit.CreateNewElement();
		ListNodes(depth, parent, pme);
		delete pme;
	}
}
else if ((pe->GetType() & 0x0ff00000) == ITEM_IS_PACKAGE)
{
	wxString filename;
	wxDir dir(path.GetPath());

	for (int i = 0; i < depth; ++i)
		putchar('\t');
	printf("subgraph cluster%s {\n",
		path.GetDirs()[path.GetDirCount()-1].c_str());
	for (int i = 0; i <= depth; ++i)
		putchar('\t');
	printf("label = \"Package: %s\"; labeljust=left; fontname=arial; fontsize=10; color=red;\n", pe->GetName().c_str());
	AdeDirectoryElement de(path);
	for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
	{
		AdeModelElement* pme = eit.CreateNewElement();
		ListNodes(depth + 1, parent, pme);
		delete pme;
	}
	for (int i = 0; i < depth; ++i)
		putchar('\t');
	puts("}");
}
