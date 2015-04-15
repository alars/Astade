//~~ void doGoto(tr::Section* subSection) [Section] ~~
currentLine = 0;

if (currentSubsection < mNameOrder.size())
{
    std::string name = mNameOrder[currentSubsection];
    boost::shared_ptr<tr::Section> aSection = mySubSections[name];
    aSection->reportEnd();
}

for (unsigned int i = 0; i < mNameOrder.size(); i++)
{
    std::string name = mNameOrder[i];
    boost::shared_ptr<tr::Section> aSection = mySubSections[name];
    if (aSection.get() == subSection)
    {
        currentSubsection = i;
        return;
    }
}
