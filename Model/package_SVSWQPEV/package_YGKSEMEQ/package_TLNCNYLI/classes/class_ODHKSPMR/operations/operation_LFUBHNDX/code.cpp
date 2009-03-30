wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName make(theConfig->Read("Tools/Make"));

wxFileName configurationPath = configuration.GetFileName();
configurationPath.MakeAbsolute();

wxFileName componentPath = configuration.GetFileName();
componentPath.MakeAbsolute();
componentPath.RemoveLastDir();
AdeComponent* component = dynamic_cast<AdeComponent*>(AdeModelElement::CreateNewElement(componentPath));
assert(component);

wxString command = make.GetFullPath() + " -C \"" +
	configurationPath.GetPath() +
	"\" " +
	"TRACECLASSES=\"" + GetTraceClassList() + "\" TARGET=" +
	component->GetLabel() +
	" " + target;

delete component;

assert(myMakeOutput);
myMakeOutput->SetNormalStyle();
myMakeOutput->TheEdit()->Clear();
*(myMakeOutput->TheEdit()) << "make started ... \n";
myMakeOutput->SetactiveConfiguration(configurationPath);

myMakeOutput->Show();
myMakeOutput->Maximize(false); //true, maximizes the window, otherwise it restores it.
myMakeOutput->Raise();

theMakeProcess = new AstadeMakeProcess;

wxExecute(command, wxEXEC_ASYNC, theMakeProcess);
theMakeProcess->theMakeInputStream = theMakeProcess->GetInputStream();
theMakeProcess->theMakeErrorStream = theMakeProcess->GetErrorStream();
