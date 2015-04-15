//~~ void beautify(unsigned int indent) [ShellTrigger] ~~
std::cout 
    << "shell(\""
    << esc(mCommand)
    << "\") -> ";
    
Trigger::beautify(indent);
