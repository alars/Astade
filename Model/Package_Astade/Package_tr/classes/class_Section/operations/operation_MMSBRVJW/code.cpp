//~~ bool hasLines() [Section] ~~
if (currentLine < myLines.size())
    RETURN(true);

if (currentSubsection < mNameOrder.size())
{
    std::string name = mNameOrder[currentSubsection];
    boost::shared_ptr<tr::Section> aSection = mySubSections[name];
    RETURN(aSection->hasLines());
}

RETURN(false);