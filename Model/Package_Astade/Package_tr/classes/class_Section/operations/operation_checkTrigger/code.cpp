//~~ bool checkTrigger(RunnerInterface& runner, std::string& data, unsigned int mSecTime, unsigned int& current_mSecTimeout) [Section] ~~
if (currentSubsection < mNameOrder.size())
{
    std::string name = mNameOrder[currentSubsection];
    boost::shared_ptr<tr::Section> aSection = mySubSections[name];
    bool subTriggered;
    if (aSection)
        subTriggered = aSection->checkTrigger(runner,data,mSecTime,current_mSecTimeout);
        
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

RETURN(false);