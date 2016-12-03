//~~ void SetDefault(wxCommandEvent& event) [AstadeDirDialog] ~~

wxString datadir(wxStandardPaths::Get().GetDataDir());
datadir += wxFileName::GetPathSeparator();
wxFileName exec(wxStandardPaths::Get().GetExecutablePath());
wxString execdir(exec.GetPath());
execdir += wxFileName::GetPathSeparator();

featureEditPathTextControl->SetValue(execdir + wxS("ResourceEdit"));
#if defined(__WXMSW__)
omdPathTextControl->SetValue(execdir + wxS("omd.bat"));
statechartPathTextControl->SetValue(execdir + wxS("sc.bat"));
compositeStructurePathTextControl->SetValue(execdir + wxS("csd.bat"));
#elif defined(__WXMAC__)
omdPathTextControl->SetValue(datadir + wxS("Templates/Scripts/Mac/ObjectModelDiagram.sh"));
statechartPathTextControl->SetValue(datadir + wxS("Templates/Scripts/Mac/StateChart.sh"));
compositeStructurePathTextControl->SetValue(datadir + wxS("Templates/Scripts/Mac/CompositeStructureDiagram.sh"));
#else
omdPathTextControl->SetValue(datadir + wxS("Templates/Scripts/Linux/ObjectModelDiagram.sh"));
statechartPathTextControl->SetValue(datadir + wxS("Templates/Scripts/Linux/StateChart.sh"));
compositeStructurePathTextControl->SetValue(datadir + wxS("Templates/Scripts/Linux/CompositeStructureDiagram.sh"));
#endif
coderPathTextControl->SetValue(execdir + wxS("CppGenerator"));
ccoderPathTextControl->SetValue(execdir + wxS("CGenerator"));
pythoncoderPathTextControl->SetValue(execdir + wxS("PythonGenerator"));
statechartCoderPathTextControl->SetValue(execdir + wxS("StateChartCoder"));
makePathTextControl->SetValue(wxS("make"));
templatesPathTextControl->SetValue(datadir + wxS("Templates"));
sequencesPathTextControl->SetValue(execdir + wxS("Trace2UML"));
usecasePathTextControl->SetValue(execdir + wxS("AstadeDraw"));
DoxWizTextControl->SetValue(wxS("doxywizard"));
codeEditPathTextControl->SetValue(execdir + wxS("CodeEdit"));
editLineOption->SetValue(wxS("--line="));
