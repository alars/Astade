//~~ void beautify(unsigned int indent) [TextTrigger] ~~
std::cout 
    << std::setw(indent)
    << " "
    << "watch: \""
    << mTriggerText
    << "\" -> ";
    
Trigger::beautify(indent);
