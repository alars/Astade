//~~ bool hasLines() [Section] ~~
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

RETURN(false);