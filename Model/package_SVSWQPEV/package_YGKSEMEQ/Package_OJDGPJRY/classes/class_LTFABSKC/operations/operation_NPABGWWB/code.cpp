wxString rowName;
rowName.Printf("/Row_%08X",reinterpret_cast<unsigned int>(this));

for (std::list<ACNode*>::iterator it = myNodes.begin(); it != myNodes.end(); ++it)
{
	config.SetPath(rowName);
	(*it)->Save(config);
}