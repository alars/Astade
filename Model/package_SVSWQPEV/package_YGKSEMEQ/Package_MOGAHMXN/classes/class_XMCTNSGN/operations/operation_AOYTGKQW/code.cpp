if (indexBase == -1) // not yet initialized
	InitializeIcons();

int ret = indexBase;

if (static_cast<AdeClass*>(myModelElement)->IsCCoded())
	ret += 5;

wxFileName aName = static_cast<AdeClass*>(myModelElement)->GetImpFileName();

if (aName.FileExists())
{   
    wxDateTime access,mod,create;
    aName.GetTimes(&access,&mod,&create);
    if (mod > create)
    {
        ret += 4;
        return ret;
    }
}

aName.SetExt("h");

if (aName.FileExists())
{   
    wxDateTime access,mod,create;
    aName.GetTimes(&access,&mod,&create);
    if (mod > create)
    {
        ret += 4;
        return ret;
    }
}

if (static_cast<AdeClass*>(myModelElement)->IsLibClass())
	ret += 3;
else if (static_cast<AdeClass*>(myModelElement)->IsInActiveComponent())
{
	if (static_cast<AdeClass*>(myModelElement)->GetImpGenerationTime() >= static_cast<AdeClass*>(myModelElement)->GetModificationTime())
		ret += 1;
	else
		ret += 2;
}

return ret;
