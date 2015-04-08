//~~ std::string esc(const std::string& data) [strEsc] ~~
std::string ret;
for (unsigned int i = 0; i < data.size(); i++)
{
    char c = data[i];
    switch (c) {
        case '\a':
            ret += "\\a";
        break;
        case '\b':
            ret += "\\b";
        break;
        case '\f':
            ret += "\\f";
        break;
        case '\n':
            ret += "\\n";
        break;
        case '\r':
            ret += "\\r";
        break;
        case '\t':
            ret += "\\t";
        break;
        case '\v':
            ret += "\\v";
        break;
        case '\\':
            ret += "\\\\";
        break;
        case '"':
            ret += "\\\"";
        break;
        case '\'':
            ret += "\\'";
        break;
        default: ret += c;
    }
}
return ret;