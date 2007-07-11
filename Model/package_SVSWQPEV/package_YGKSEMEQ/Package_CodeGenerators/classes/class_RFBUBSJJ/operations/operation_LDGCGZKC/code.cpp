/* vi: set tabstop=4: */

std::list<const AdeRelation*>::iterator it;
for (it = Relations.begin(); it != Relations.end(); ++it)
{
	wxString Default((*it)->GetDefault());
	if (!Default.empty())
	{
		wxString RelationName((*it)->GetName());
		memberDefaults[RelationName] = Default;
		AttributeList.push_back(RelationName);
	}
	out << "/** " << (const char*)(*it)->GetDescription() << std::endl;
	out << "*/"   << std::endl;

	out << "\t" << (const char*)(*it)->GetImplementation()
		<< "\t" << (const char*)(*it)->GetName()
		<< ";"  << std::endl;
	out << std::endl;
}
