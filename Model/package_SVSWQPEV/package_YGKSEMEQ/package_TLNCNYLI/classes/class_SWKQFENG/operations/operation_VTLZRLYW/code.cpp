Hide();
wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/OmdViewPath"));

wxString callName = "\"" + coder.GetFullPath() + "\" " +
	"\"" + diagramSource.GetFullPath() + "\"";

wxExecute(callName);