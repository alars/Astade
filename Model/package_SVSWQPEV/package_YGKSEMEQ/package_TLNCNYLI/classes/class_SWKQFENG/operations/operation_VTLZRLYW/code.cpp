Hide();
wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/OmdViewPath"));

wxString callName = "\"" + coder.GetFullPath() + "\" " +
	"\"" + diagramSource.GetFullPath() + "\"";

if (externalCheckBox->IsChecked())
	callName += " -e";

if (notInComponentCheckBox->IsChecked())
	callName += " -s";

wxString verbose;
verbose.Printf(" -a %d -o %d",attributesRadioBox->GetSelection(),operationsRadioBox->GetSelection());

callName += verbose;

wxExecute(callName);