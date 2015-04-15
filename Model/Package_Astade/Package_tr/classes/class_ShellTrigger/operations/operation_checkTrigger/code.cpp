//~~ bool checkTrigger(std::string& data) [ShellTrigger] ~~
int res = system(mCommand.c_str());
if (res)
    fire();
return true;