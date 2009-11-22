/* vi: set tabstop=4: */

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

			out << "/** " << (const char*)pr->GetDescription().c_str()
				<< std::endl;
			out << "*/"   << std::endl;

			out << "\t";
			if (pr->IsStatic())
				out << "static ";
			out << (const char*)pr->GetImplementation().c_str()
				<< "\t" << (const char*)RelationName.c_str()
				<< ";"  << std::endl;
			out << std::endl;
		}
		else if (pr->IsStatic())
		{
			out << (const char*)pr->GetImplementation().c_str()
				<< "\t"  << (const char*)source->GetName().c_str()
				<< "::"  << (const char*)RelationName.c_str();
			wxString Default(pr->GetDefault());
			if (!Default.empty())
				out << " = " << (const char*)Default.c_str();
			out << ";" << std::endl;
		}
	}
}
