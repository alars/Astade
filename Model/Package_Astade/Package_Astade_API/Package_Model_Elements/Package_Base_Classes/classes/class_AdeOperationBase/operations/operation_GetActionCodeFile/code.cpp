//~~ wxFileName GetActionCodeFile() [AdeOperationBase] ~~

wxFileName codeSource = myFileName;
codeSource.SetFullName(wxS("code.cpp"));
if (!wxFile::Exists(codeSource.GetFullPath()))
{
	// "code.cpp" doesn't exist, look for "code.<language_ext>"
	codeSource.SetExt(GetImpExtension());
}
return codeSource;
