//~~ void beautify(unsigned int indent) [TextTrigger] ~~
std::cout 
    << "\""
    << esc(mTriggerText)
    << "\" -> ";
    
Trigger::beautify(indent);
