// vi: set tabstop=4:
wxFileName path = pe->GetFileName();
AdeDirectoryElement de(path);

if ((pe->GetType() & 0x0ff00000) == ITEM_IS_CLASS)
{
	wxString prename(parent);
	if (!parent.IsEmpty())
		prename = prename + ":" + pe->GetName();
	else
		prename = pe->GetName();
	wxString nodename(path.GetDirs()[path.GetDirCount()-1]);
	nodelist.insert(nodename);
	std::cout << std::endl;
	for (int i = 0; i < depth; ++i)
		std::cout << '\t';
	std::cout << path.GetDirs()[path.GetDirCount()-1]
		<< " [shape=record, label=\"{"
		<< prename
		<< '|';
	if (showattr != NONE)
		ListAttributes(pe);
	std::cout << '|';
	if (showoper != NONE)
		ListOperations(pe);
	std::cout << "}\", style=filled, fillcolor=grey95, color=black];"
		<< std::endl;

	for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
	{
		AdeModelElement* pme = eit.CreateNewElement();
		ListNodes(depth, prename, pme);
		delete pme;
	}
}
else if ((pe->GetType() & 0x0ff00000) == ITEM_IS_CLASSES)
{
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
		std::cout << '\t';
	std::cout << "subgraph cluster"
		<< path.GetDirs()[path.GetDirCount()-1]
		<< " {"
		<< std::endl;
	for (int i = 0; i <= depth; ++i)
		std::cout << '\t';
	std::cout << "label = \"Package: "
		<< pe->GetName()
		<< "\"; labeljust=left; fontname=Helvetica; fontsize=10; color=red;"
		<< std::endl;
	for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
	{
		AdeModelElement* pme = eit.CreateNewElement();
		ListNodes(depth + 1, parent, pme);
		delete pme;
	}
	for (int i = 0; i < depth; ++i)
		std::cout << '\t';
	std::cout << '}'
		<< std::endl;
}
