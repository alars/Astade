//~~ void relationAttribute(std::ofstream& out, bool spec) [CGenerator] ~~

std::multiset<const AdeRelation*>::iterator it;
for (it = Relations.begin(); it != Relations.end(); ++it)
{
	if (!(*it)->GetImplementation().empty())
	{
		wxString RelationName((*it)->GetName());
		if (spec)
		{
			if (!(*it)->IsStatic())
			{
				wxString Default((*it)->GetDefault());
				if (!Default.empty())
				{
					memberDefaults[RelationName] = Default;
					AttributeList.push_back(RelationName);
				}

			    out << "/** " << (*it)->GetDescription()
				    << std::endl;
			    out << "*/"   << std::endl;

			    out << "\t";
			    if ((*it)->IsStatic())
				    out << "static ";
			    out << (*it)->GetImplementation()
				    << "\t" << RelationName
				    << ";"  << std::endl;
			    out << std::endl;

			}
		}
		else if ((*it)->IsStatic())
		{
			out << "/** " << (*it)->GetDescription()
				<< std::endl;
			out << "*/"   << std::endl;

			out << (*it)->GetImplementation()
				<< "\t" << source->GetName()
				<< "_"  << RelationName;
			wxString Default((*it)->GetDefault());
			if (!Default.empty())
				out << " = " << Default;
			out << ";" << std::endl << std::endl;
		}
	}
}
