/* vi: set tabstop=4: */

std::list<const AdeRelation*>::iterator it;
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
			}

			out << "/** " << (const char*)(*it)->GetDescription().c_str()
				<< std::endl;
			out << "*/"   << std::endl;

			out << "\t";
			if ((*it)->IsStatic())
				out << "static ";
			out << (const char*)(*it)->GetImplementation().c_str()
				<< "\t" << (const char*)RelationName.c_str()
				<< ";"  << std::endl;
			out << std::endl;
		}
		else if ((*it)->IsStatic())
		{
			out << (const char*)(*it)->GetImplementation().c_str()
				<< "\t"  << (const char*)source->GetName().c_str()
				<< "::"  << (const char*)RelationName.c_str();
			wxString Default((*it)->GetDefault());
			if (!Default.empty())
				out << " = " << (const char*)Default.c_str();
			out << ";" << std::endl;
		}
	}
}
