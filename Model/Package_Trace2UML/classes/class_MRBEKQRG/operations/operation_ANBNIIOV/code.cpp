//~~ bool operator<(const SeqConnection& other) [SeqConnection] ~~
RETURN(
    (sourcePtr < other.sourcePtr) ||
    (sourceClass < other.sourceClass) ||
    (sourcePort < other.sourcePort) ||
    (destPtr < other.destPtr) ||
    (destClass < other.destClass) ||
    (destPort < other.destPort)
);