//~~ boost::shared_ptr<tr::Section> findSection(const std::string& name) [Section] ~~
std::map<std::string, boost::shared_ptr<tr::Section> >::iterator it = mySubSections.find(name);
if (it != mySubSections.end())
    return (*it).second;
else
    return boost::shared_ptr<tr::Section>();