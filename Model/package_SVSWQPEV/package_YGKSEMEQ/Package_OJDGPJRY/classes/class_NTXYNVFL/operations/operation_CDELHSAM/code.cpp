int i = 1;
wxString nodeName;
nodeName.Printf("/Rows/Row_%d",i);
while (config.Exists(nodeName))
{
	config.SetPath(nodeName);
	ACRow* aRow = new ACRow;
	aRow->Load(config);
	myRows.push_back(aRow);
	nodeName.Printf("/Rows/Row_%d",++i);
}