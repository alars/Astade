//~~ unsigned int messageCount() [ACF] ~~
int diff = nextWrite - nextRead;
if (diff >= 0)
    return diff;
else
    return my_Messages.size() + diff; // diff is negative!