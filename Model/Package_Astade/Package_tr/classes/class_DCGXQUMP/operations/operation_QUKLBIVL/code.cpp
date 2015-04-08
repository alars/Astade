//~~ void beautify(unsigned int indent) [Section] ~~
for (std::vector<std::string>::iterator it = mNameOrder.begin(); it != mNameOrder.end(); it++)
{
    boost::shared_ptr<tr::Section> sub = mySubSections[*it];
    std::cout 
        << std::setw(indent)
        << sub->keyword()
        << " "
        << (*it)
        << " {"
        << std::endl;

    sub->beautify(indent + 4);

    std::cout 
        << std::setw(indent)
        << "}"
        << std::endl
        << std::endl;
}