Hide();
wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/OmdViewPath"));

wxString callName = "\"" + coder.GetFullPath() + "\"";

if (externalCheckBox->IsChecked())
	callName += " -e";

if (notInComponentCheckBox->IsChecked())
	callName += " -s";

wxString verbose;
verbose.Printf(" -a %d -o %d", attributesRadioBox->GetSelection(), operationsRadioBox->GetSelection());
callName += verbose;

diagramSource.MakeRelativeTo();
callName += " \"" + diagramSource.GetFullPath() + "\"";

wxExecute(callName);
