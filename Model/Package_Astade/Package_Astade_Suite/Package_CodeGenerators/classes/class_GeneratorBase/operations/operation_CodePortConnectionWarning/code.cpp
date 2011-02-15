//~~ void CodePortConnectionWarning(std::ofstream& out) [GeneratorBase] ~~

AdeConnections* theConnections = source->GetConnections();

if (theConnections)
{
    if (theConnections->begin() != theConnections->end())
	{
        out << "\n#warning this class uses port connections but has no generated constructor. This will probably not work correct." << std::endl;
	}
    delete theConnections;
}
