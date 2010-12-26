//~~ void SetDefault(wxCommandEvent& event) [AstadeDirDialog] ~~
wxString datadir(wxStandardPaths::Get().GetDataDir());
datadir += wxFileName::GetPathSeparator();
wxFileName exec(wxStandardPaths::Get().GetExecutablePath());
wxString execdir(exec.GetPath());
execdir += wxFileName::GetPathSeparator();

featureEditPathTextControl->SetValue(execdir + "ResourceEdit");
#if defined(__WXMSW__)
omdPathTextControl->SetValue(execdir + "omd.bat");
statechartPathTextControl->SetValue(execdir + "sc.bat");
compositeStructurePathTextControl->SetValue(execdir + "csd.bat");
#elif defined(__WXMAC__)
omdPathTextControl->SetValue(datadir + "Templates/Scripts/Mac/ObjectModelDiagram.sh");
statechartPathTextControl->SetValue(datadir + "Templates/Scripts/Mac/StateChart.sh");
compositeStructurePathTextControl->SetValue(datadir + "Templates/Scripts/Mac/CompositeStructureDiagram.sh");
#else
omdPathTextControl->SetValue(datadir + "Templates/Scripts/Linux/ObjectModelDiagram.sh");
statechartPathTextControl->SetValue(datadir + "Templates/Scripts/Linux/StateChart.sh");
compositeStructurePathTextControl->SetValue(datadir + "Templates/Scripts/Linux/CompositeStructureDiagram.sh");
#endif
coderPathTextControl->SetValue(execdir + "CppGenerator");
ccoderPathTextControl->SetValue(execdir + "CGenerator");
statechartCoderPathTextControl->SetValue(execdir + "StateChartCoder");
makePathTextControl->SetValue("make");
templatesPathTextControl->SetValue(datadir + "Templates");
sequencesPathTextControl->SetValue(execdir + "Trace2UML");
usecasePathTextControl->SetValue(execdir + "AstadeDraw");
DoxWizTextControl->SetValue("doxywizard");
codeEditPathTextControl->SetValue(execdir + "CodeEdit");
editLineOption->SetValue("--line=");