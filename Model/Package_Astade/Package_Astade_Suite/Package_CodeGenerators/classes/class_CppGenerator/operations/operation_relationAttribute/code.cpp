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

			out << "/** " << pr->GetDescription()
				<< std::endl;
			out << "*/"   << std::endl;

			out << "\t";
			if (pr->IsStatic())
				out << "static ";
			out << pr->GetImplementation()
				<< "\t" << RelationName
				<< ";"  << std::endl;
			out << std::endl;
		}
		else if (pr->IsStatic())
		{
			out << pr->GetImplementation()
				<< "\t"
				<< getNamespace(source->getNamespace())
				<< source->GetName()
				<< "::"
				<< RelationName;
			wxString Default(pr->GetDefault());
			if (!Default.empty())
				out << " = " << Default;
			out << ";" << std::endl;
		}
	}
}
