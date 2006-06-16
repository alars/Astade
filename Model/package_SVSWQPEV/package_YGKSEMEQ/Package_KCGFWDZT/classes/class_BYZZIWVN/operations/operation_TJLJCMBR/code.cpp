wxString RelatedClass = wxConfigBase::Get()->Read("Astade/PartnerClassname",wxEmptyString);

wxString buffer;
wxArrayString ret;
buffer.Printf("%s*",RelatedClass.c_str());
ret.Add(buffer);
buffer.Printf("%s",RelatedClass.c_str());
ret.Add(buffer);
buffer.Printf("std::set<%s *>",RelatedClass.c_str());
ret.Add(buffer);
buffer.Printf("std::list<%s *>",RelatedClass.c_str());
ret.Add(buffer);
buffer.Printf("std::vector<%s *>",RelatedClass.c_str());
ret.Add(buffer);
buffer.Printf("std::deque<%s *>",RelatedClass.c_str());
ret.Add(buffer);
buffer.Printf("std::map<%s *, ?>",RelatedClass.c_str());
ret.Add(buffer);
return ret;