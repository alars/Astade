wxString rowName;
rowName.Printf("/Row_%p", this);

for (std::list<ACNode*>::iterator it = myNodes.begin(); it != myNodes.end(); ++it)
{
	config.SetPath(rowName);
	(*it)->Save(config);
}
