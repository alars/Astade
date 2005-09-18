wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");

if (activeComponentName.SameAs(myFileName))
	return 42;
else
	return 6;