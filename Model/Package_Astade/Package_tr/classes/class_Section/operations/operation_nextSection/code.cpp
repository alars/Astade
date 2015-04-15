//~~ void nextSection() [Section] ~~
currentLine = 0;

if (currentSubsection < mNameOrder.size())
{
    std::string name = mNameOrder[currentSubsection];
    boost::shared_ptr<tr::Section> aSection = mySubSections[name];
    aSection->reportEnd();
}

currentSubsection++;
if (!hasLines())
{
    Section* p = getParent();
    if (p)
        p->nextSection();
}