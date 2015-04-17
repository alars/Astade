//~~ bool checkTimeout(std::string& data, bool down) [Section] ~~

if (down && (currentSubsection < mNameOrder.size()))
{
    std::string name = mNameOrder[currentSubsection];
    boost::shared_ptr<tr::Section> aSection = mySubSections[name];
    bool subTriggered = false;
    if (aSection)
        subTriggered = aSection->checkTimeout(data, true);
        
    if (subTriggered)
        RETURN(true);
}

if (currentLine < myLines.size())
{
    if (myLines[currentLine]->checkTimeout(data))
    {
        currentLine++;
        RETURN(true);
    }
}

for (std::vector< boost::shared_ptr<Trigger> >::iterator it = myWatches.begin(); it != myWatches.end(); it++)
{
    if ((*it)->checkTimeout(data))
        RETURN(true);
}

if (!down)
{
    Section* p = getParent();
    if (p)
    {
        RETURN(p->checkTimeout(data, false));
    } else {
        RETURN(false);
    }
}

RETURN(false);
