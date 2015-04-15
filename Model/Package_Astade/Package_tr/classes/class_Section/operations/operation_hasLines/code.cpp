//~~ bool hasLines() [Section] ~~
if (!runReported)
{
    reportBegin();
    runReported = true;
}

if (currentLine < myLines.size())
    RETURN(true);

while (currentSubsection < mNameOrder.size())
{
    std::string name = mNameOrder[currentSubsection];
    boost::shared_ptr<tr::Section> aSection = mySubSections[name];
    if (aSection->hasLines())
        RETURN(true);
    currentSubsection++;
}

reportEnd();

RETURN(false);