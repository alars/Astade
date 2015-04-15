//~~ bool checkTrigger(std::string& data) [Section] ~~
if (!runReported)
{
    reportBegin();
    runReported = true;
}

if (currentSubsection < mNameOrder.size())
{
    std::string name = mNameOrder[currentSubsection];
    boost::shared_ptr<tr::Section> aSection = mySubSections[name];
    bool subTriggered;
    if (aSection)
        subTriggered = aSection->checkTrigger(data);
        
    if (subTriggered)
        RETURN(true);
}

if (currentLine < myLines.size())
{
    if (myLines[currentLine]->checkTrigger(data))
    {
        currentLine++;
        RETURN(true);
    }
}

if (checkWatch(data))
    RETURN(true);

RETURN(false);