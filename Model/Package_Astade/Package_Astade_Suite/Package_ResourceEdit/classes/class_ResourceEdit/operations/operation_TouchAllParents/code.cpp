wxFileName aFileName(wxApp::GetInstance()->argv[1]);
aFileName.SetFullName("ModelNode.ini");

while (aFileName.FileExists())
{
	aFileName.Touch();
	aFileName.RemoveLastDir();
}