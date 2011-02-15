//~~ void CodePortConnectionWarning(std::ofstream& out) [GeneratorBase] ~~

AdeConnections* theConnections = source->GetConnections();

if (theConnections)
{
	if (theConnections->begin() != theConnections->end())
	{
		out << "\n#warning This class uses port connections but has no constructor. This will probably not work correctly." << std::endl;
	}
	delete theConnections;
}
