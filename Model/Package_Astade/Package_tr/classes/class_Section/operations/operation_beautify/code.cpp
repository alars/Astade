//~~ void beautify(unsigned int indent) [Section] ~~
for (std::vector<std::string>::iterator it = mNameOrder.begin(); it != mNameOrder.end(); it++)
{
    boost::shared_ptr<tr::Section> sub = mySubSections[*it];
    if (indent)
        std::cout << std::setw(indent) << " ";
        
    std::cout 
        << sub->keyword()
        << " "
        << (*it)
        << " {"
        << std::endl;

    for (std::vector< boost::shared_ptr<Trigger> >::iterator it2 = myWatches.begin(); it2 != myWatches.end(); it2++)
    {
        (*it2)->beautify(indent + 4);
    }

    sub->beautify(indent + 4);

    std::cout 
        << std::setw(indent)
        << "}"
        << std::endl
        << std::endl;
}