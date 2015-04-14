//~~ unsigned int getTimeout() [Section] ~~
if (currentSubsection < mNameOrder.size())
{
    std::string name = mNameOrder[currentSubsection];
    boost::shared_ptr<tr::Section> aSection = mySubSections[name];
    RETURN(aSection->getTimeout());
} else {
    RETURN(mTimeout);
}