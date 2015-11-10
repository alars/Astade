//~~ wxArrayString getRelativeNamespace(const AdeClass* aClass) [CppGenerator] ~~

wxArrayString source_space(source->getNamespace());
wxArrayString target_space(aClass->getNamespace());
unsigned int ix;
for (ix = 0; ix < source_space.GetCount() && ix < target_space.GetCount(); ++ix)
	if (source_space[ix] != target_space[ix])
		break;
if (ix > 0)
    target_space.RemoveAt(0, ix);
return target_space;
