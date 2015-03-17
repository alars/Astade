//~~ const char* getName(const AQF_MessageReceiver* object) [AQF_MessageReceiver] ~~
int status;
const char *realname = abi::__cxa_demangle(typeid(*object).name(), 0, 0, &status);

const char* ns = strstr(realname, "::");

while (ns)
{
    realname = ns + 2;
    ns = strstr("::",realname);
}

return realname;