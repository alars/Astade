std::list<AdeParameter*> parameterlist = op.Parameterlist();
std::list<wxString> constraints;

for (std::list<AdeParameter*>::iterator it = parameterlist.begin(); it != parameterlist.end(); ++it)
{
	wxString constraint = (*it)->GetConstraint();
	if (!constraint.empty())
	{
		constraint.Replace("%s",(*it)->GetName());
		constraints.push_back("\tCONSTRAINT("+constraint+");");
	}
	delete (*it);
}

if (!constraints.empty())
{
	out << std::endl << "#ifdef CONSTRAINT" << std::endl;
	
	for (std::list<wxString>::iterator it = constraints.begin(); it != constraints.end(); ++it)
		out << (*it) << std::endl;
	
	out << "#endif" << std::endl << std::endl;
}
