/* vi: set tabstop=4: */

std::list<const AdeRelation*>::iterator it;
for (it = Relations.begin(); it != Relations.end(); ++it)
{
	out << "/** " << (*it)->GetDescription() << std::endl;
	out << "*/"   << std::endl;

	out << "\t" << (*it)->GetImplementation()
		<< "\t" << (*it)->GetName()
		<< ";" << std::endl;
	out << std::endl;
}
