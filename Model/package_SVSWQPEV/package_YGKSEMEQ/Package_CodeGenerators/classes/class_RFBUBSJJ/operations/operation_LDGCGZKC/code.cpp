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
	out << "/** " << (*it)->GetDescription() << std::endl;
	out << "*/"   << std::endl;

	out << "\t" << (*it)->GetImplementation()
		<< "\t" << (*it)->GetName()
		<< ";" << std::endl;
	out << std::endl;
}
