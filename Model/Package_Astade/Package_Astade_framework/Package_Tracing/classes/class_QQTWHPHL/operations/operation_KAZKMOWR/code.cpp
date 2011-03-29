//~~ const std::string& setRetval(const std::string& aRetVal) [Trace2UML] ~~
std::string a("\"");
std::string sub = aRetVal.substr(0,15);

for (unsigned i = 0; i < sub.size(); i++) {
    if (sub[i]<=0x20 || sub[i]>=0x80)
        sub[i] = '?';
}

if (sub.size() < aRetVal.size())
    sub += "...";

retval = a + aRetVal + a;
return aRetVal;