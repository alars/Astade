if (indexBase == -1) // not yet initialized
	InitializeIcons();

int ret = indexBase;
wxFileName aName = myModelElement->GetFileName();

if (aName.GetExt()=="h")
    ret += 1;
if (aName.GetExt()=="dox")
    ret += 2;
if (aName.GetExt()=="c")
    ret += 3;

wxDateTime access,mod,create;
aName.GetTimes(&access,&mod,&create);

if (aName.GetDirs().Last() == "auto")
    if (mod > create)
        ret += 4;

return ret;

return 0;