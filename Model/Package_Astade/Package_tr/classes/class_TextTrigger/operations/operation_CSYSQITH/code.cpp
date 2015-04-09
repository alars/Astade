//~~ bool checkTrigger(std::string& data) [TextTrigger] ~~
size_t pos = data.find(mTriggerText);
if(pos != std::string::npos)
{   // found
    data.erase(0,pos+mTriggerText.size());
    fire();
    return true;
}
return false;