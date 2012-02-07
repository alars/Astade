//~~ void DisplayOMD(wxCommandEvent& event) [AstadeOmdDialog] ~~

Hide();
wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read(wxS("Tools/OmdViewPath")));

wxString callName(wxS("\"") + coder.GetFullPath() + wxS("\""));

if (externalCheckBox->IsChecked())
	callName += wxS(" -e");

if (notInComponentCheckBox->IsChecked())
	callName += wxS(" -s");

if (drawPortsCheckBox->IsChecked())
	callName += wxS(" -p");

wxString verbose;
verbose.Printf(wxS(" -a %d -o %d"), attributesRadioBox->GetSelection(), operationsRadioBox->GetSelection());
callName += verbose;

diagramSource.MakeRelativeTo();
callName += wxS(" \"") + diagramSource.GetFullPath() + wxS("\"");

wxExecute(callName);
