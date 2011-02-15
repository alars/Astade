//~~ int messageCount() [ACF] ~~
int diff = ACF_nextWrite - ACF_nextRead;
if (diff >= 0)
    return diff;
else
    return ACF_MESSAGEQUEUESIZE + diff; // diff is negative!