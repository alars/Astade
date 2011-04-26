//~~ void dec() [ACF_MessageData] ~~
refcount--;
if (refcount == 0)
    delete this;