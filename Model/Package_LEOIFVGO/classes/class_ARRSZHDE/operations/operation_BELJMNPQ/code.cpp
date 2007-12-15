wxString message = _T( \
"  symbol	description\n\n" \
"	;	lines starting with ';' are comments. They are not drawn.\n" \
"	#	lines starting with '#' are visible comments. They are drawn with a horizontal line.\n" \
"	!	this is used to notify the existence of an object (the creation is not in the scope of the trace).\n" \
"		This is automatically inserted when you use an object name not mentioned before.\n" \
"	(!)	this is used to notify an object creation.\n" \
"	(X)	this is used to notify an object deletion.\n" \
"	>--	this is used to notify an asynchronous message send.\n" \
"	-->	this is used to notify an asynchronous message receive.\n" \
"	>->	this is a shortcut when typing traces by hand.\n" \
"		Creates both an asynchronous message send and a corresponding message receive.\n" \
"	==>	this is used to notify a synchronous function call.\n" \
"	<==	this is used to notify a synchronous function return.\n" \
"	>>>	this is used to notify a state change.\n" \
"	[...]	everything set into square brackets is treated as user data.\n" \
"		It stays in the trace line without having any effect on the graphics.\n" \
"		You can use it for timestamps or remarks.\n");

wxDialog aDialog(this, -1, _T("Trace2UML Commands"), wxDefaultPosition, wxDefaultSize, wxRESIZE_BORDER | wxDEFAULT_DIALOG_STYLE );
wxTextCtrl aText(&aDialog, -1, message, wxDefaultPosition,wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY );
aDialog.SetSize(-1, -1, 650, 350);
aDialog.Center();

aDialog.ShowModal();
