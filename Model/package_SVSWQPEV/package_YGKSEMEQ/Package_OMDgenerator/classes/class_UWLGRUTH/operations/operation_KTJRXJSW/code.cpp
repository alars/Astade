wxFileName dirname(path);
dirname.SetFullName("ModelNode.ini");
int type = 0;
wxGetResource("Astade", "Type", &type, dirname.GetFullPath());
if ((0xFF00000 & type) == ITEM_IS_CLASS) 
{
	wxChar* name = NULL;
	wxGetResource("Astade", "Name", &name, dirname.GetFullPath());
	wxString prename;

	if (strlen(parent))
	{
		prename = parent;
		prename = prename + ":" + name;
	}
	else
		prename = name; 
	delete [] name;

	for (int i = 0; i < depth; ++i)
		printf("\t");

	wxString nodename(dirname.GetDirs()[dirname.GetDirCount()-1]);
	nodelist[nodename] = true;

	printf("%s [label=\"%s\", style=filled, fillcolor=grey95, color=black];\n", dirname.GetDirs()[dirname.GetDirCount()-1].c_str(), prename.c_str());

	wxString filename;
	wxDir dir(dirname.GetPath());

	bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
	while (cont)
	{
		wxFileName FullName(dirname);
		FullName.AppendDir(filename);
		ListNodes(depth, prename.c_str(), FullName.GetFullPath().c_str());
		cont = dir.GetNext(&filename);
	}
}

if ((0xFF00000 & type) == ITEM_IS_CLASSES) 
{
	wxString filename;
	wxDir dir(dirname.GetPath());

	bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
	while (cont)
	{
		wxFileName FullName(dirname);
		FullName.AppendDir(filename);
		ListNodes(depth, parent, FullName.GetFullPath().c_str());
		cont = dir.GetNext(&filename);
	}
}

if ((0xFF00000 & type) == ITEM_IS_PACKAGE)
{
	wxString filename;
	wxDir dir(dirname.GetPath());

	for (int i = 0; i < depth; ++i)
		printf("\t");

	printf("subgraph cluster%s {\n", dirname.GetDirs()[dirname.GetDirCount()-1].c_str());

	wxChar* name = NULL;
	wxGetResource("Astade", "Name", &name, dirname.GetFullPath());
	for (int i = 0; i <= depth; ++i)
		printf("\t");
	printf("label = \"Package: %s\", fontname=arial, fontsize=10, color=red\n", name);
	delete [] name;

	bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
	while (cont)
	{
		wxFileName FullName(dirname);
		FullName.AppendDir(filename);
		ListNodes(depth + 1, parent, FullName.GetFullPath().c_str());
		cont = dir.GetNext(&filename);
	}
	for (int i = 0; i < depth; ++i)
		printf("\t");

	printf("}\n");
}
