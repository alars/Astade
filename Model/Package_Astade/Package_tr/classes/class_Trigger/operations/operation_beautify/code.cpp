//~~ void beautify(unsigned int indent) [Trigger] ~~
for (std::vector< boost::shared_ptr<Action> >::iterator it = myActions.begin(); it != myActions.end(); it++)
{
    if (it != myActions.begin())
        std::cout << ", ";
    (*it)->beautify(indent);
};

std::cout << ";" << std::endl;
