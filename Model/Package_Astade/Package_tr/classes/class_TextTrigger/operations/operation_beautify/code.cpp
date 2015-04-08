//~~ void beautify(unsigned int indent) [TextTrigger] ~~
std::cout 
    << std::setw(indent)
    << " "
    << "watch: \""
    << esc(mTriggerText)
    << "\" -> ";
    
Trigger::beautify(indent);
