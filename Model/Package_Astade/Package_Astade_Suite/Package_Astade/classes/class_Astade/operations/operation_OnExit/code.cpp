//~~ int OnExit() [Astade] ~~
wxConfigBase* theConfig = wxConfigBase::Get();
theConfig->Flush();

return 0;