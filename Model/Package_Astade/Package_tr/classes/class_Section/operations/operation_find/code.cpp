//~~ tr::Section* find(const std::string& target) [Section] ~~
if (down && (currentSubsection < mNameOrder.size()))
{
    std::string name = mNameOrder[currentSubsection];
    boost::shared_ptr<tr::Section> aSection = mySubSections[name];
    return aSection->find(target, true);
}


if (mySubSections.find(target) != mySubSections.end())
    return mySubSections[target].get();

if (myParent)
    return myParent->find(target,false);

return 0;