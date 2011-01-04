//~~ void AddConnectionSizer(wxSizer* topSizer) [ResourceEdit] ~~
wxBoxSizer *connection = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(connection, 0, wxEXPAND|wxRIGHT|wxLEFT, 10);
connection->Add(new wxStaticText(this, 0, "Input object:", wxDefaultPosition, wxSize(100, 15)), 0);
InputObject = new wxTextCtrl(this, -1);
connection->Add(InputObject, 1);

connection = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(connection, 0, wxEXPAND|wxRIGHT|wxLEFT, 10);
connection->Add(new wxStaticText(this, 0, "Input port:", wxDefaultPosition, wxSize(100, 15)), 0);
InputPort = new wxTextCtrl(this, -1);
connection->Add(InputPort, 1);

connection = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(connection, 0, wxEXPAND|wxRIGHT|wxLEFT|wxTOP, 10);
connection->Add(new wxStaticText(this, 0, "Output object:", wxDefaultPosition, wxSize(100, 15)), 0);
OutputObject = new wxTextCtrl(this, -1);
connection->Add(OutputObject, 1);

connection = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(connection, 0, wxEXPAND|wxRIGHT|wxLEFT, 10);
connection->Add(new wxStaticText(this, 0, "Output port:", wxDefaultPosition, wxSize(100, 15)), 0);
OutputPort = new wxTextCtrl(this, -1);
connection->Add(OutputPort, 1);

InputObject->SetValue(wxConfigBase::Get()->Read("Astade/InputObject", wxEmptyString));
OutputObject->SetValue(wxConfigBase::Get()->Read("Astade/OutputObject", wxEmptyString));
InputPort->SetValue(wxConfigBase::Get()->Read("Astade/InputPort", wxEmptyString));
OutputPort->SetValue(wxConfigBase::Get()->Read("Astade/OutputPort", wxEmptyString));
