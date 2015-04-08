//~~ void beautify(unsigned int indent) [Section] ~~
for (std::vector< boost::shared_ptr<Trigger> >::iterator it = myWatches.begin(); it != myWatches.end(); it++)
{
    (*it)->beautify(indent);
}

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

    sub->beautify(indent + 4);

    std::cout 
        << std::setw(indent)
        << "}"
        << std::endl
        << std::endl;
}