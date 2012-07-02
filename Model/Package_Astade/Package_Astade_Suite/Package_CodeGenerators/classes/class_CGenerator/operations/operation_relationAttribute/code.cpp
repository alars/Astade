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

			    out << "/** " << (*it)->GetDescription().utf8_str()
				    << std::endl;
			    out << "*/"   << std::endl;

			    out << "\t";
			    if ((*it)->IsStatic())
				    out << "static ";
			    out << (*it)->GetImplementation().utf8_str()
				    << "\t" << RelationName.utf8_str()
				    << ";"  << std::endl;
			    out << std::endl;

			}
		}
		else if ((*it)->IsStatic())
		{
			out << "/** " << (*it)->GetDescription().utf8_str()
				<< std::endl;
			out << "*/"   << std::endl;

			out << (*it)->GetImplementation().utf8_str()
				<< "\t" << source->GetName().utf8_str()
				<< "_"  << RelationName.utf8_str();
			wxString Default((*it)->GetDefault());
			if (!Default.empty())
				out << " = " << Default.utf8_str();
			out << ";" << std::endl << std::endl;
		}
	}
}
