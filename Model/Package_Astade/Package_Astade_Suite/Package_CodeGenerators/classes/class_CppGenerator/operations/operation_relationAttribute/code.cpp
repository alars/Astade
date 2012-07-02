//~~ void relationAttribute(std::ofstream& out, bool spec) [CppGenerator] ~~

std::multiset<const AdeRelation*>::iterator it;
for (it = Relations.begin(); it != Relations.end(); ++it)
{
	const AdeRelation* pr = *it;
	if (!pr->GetImplementation().empty())
	{
		wxString RelationName(pr->GetName());
		if (spec)
		{
			if (!pr->IsStatic())
			{
				wxString Default(pr->GetDefault());
				if (!Default.empty())
				{
					memberDefaults[RelationName] = Default;
					AttributeList.push_back(RelationName);
				}
			}

			out << "/** " << pr->GetDescription().utf8_str()
				<< std::endl;
			out << "*/"   << std::endl;

			out << "\t";
			if (pr->IsStatic())
				out << "static ";
			out << pr->GetImplementation().utf8_str()
				<< "\t" << RelationName.utf8_str()
				<< ";"  << std::endl;
			out << std::endl;
		}
		else if (pr->IsStatic())
		{
			out << pr->GetImplementation().utf8_str()
				<< "\t"
				<< getNamespace(source->getNamespace()).utf8_str()
				<< source->GetName().utf8_str()
				<< "::"
				<< RelationName.utf8_str();
			wxString Default(pr->GetDefault());
			if (!Default.empty())
				out << " = " << Default.utf8_str();
			out << ";" << std::endl;
		}
	}
}
