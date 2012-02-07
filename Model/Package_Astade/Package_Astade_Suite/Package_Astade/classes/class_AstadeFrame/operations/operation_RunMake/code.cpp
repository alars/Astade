//~~ void RunMake(const AdeConfiguration& configuration, const wxString& target) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName make(theConfig->Read(wxS("Tools/Make")));

wxFileName configurationPath = configuration.GetFileName();
configurationPath.MakeAbsolute();

wxFileName componentPath = configuration.GetFileName();
componentPath.MakeAbsolute();
componentPath.RemoveLastDir();
AdeComponent* component = dynamic_cast<AdeComponent*>(AdeModelElement::CreateNewElement(componentPath));
assert(component);

wxString command = make.GetFullPath() + wxS(" -C \"") +
	configurationPath.GetPath() +
	wxS("\" ") +
	wxS("\"TRACECLASSES=") + GetTraceClassList() + wxS("\" \"TARGET=") +
	component->GetLabel() +
	wxS("\" ") + target;

delete component;

assert(myMakeOutput);
myMakeOutput->SetNormalStyle();
myMakeOutput->TheEdit()->Clear();
*(myMakeOutput->TheEdit()) << wxS("make started ... \n");
myMakeOutput->SetactiveConfiguration(configurationPath);

myMakeOutput->Show();
myMakeOutput->Maximize(false); //true, maximizes the window, otherwise it restores it.
myMakeOutput->Raise();

theMakeProcess = new AstadeMakeProcess(*this);

runningMakePid = wxExecute(command, wxEXEC_ASYNC | wxEXEC_MAKE_GROUP_LEADER, theMakeProcess);
theMakeProcess->theMakeInputStream = theMakeProcess->GetInputStream();
theMakeProcess->theMakeErrorStream = theMakeProcess->GetErrorStream();
