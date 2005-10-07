myMakeOutput.theEdit.Clear();
myMakeOutput.theEdit << "make started ... \n";

myMakeOutput.Show();
theMakeProcess = new AstadeMakeProcess;

wxExecute("make -C \"F:\\Dokumente und Einstellungen\\Thomas\\Eigene Dateien\\Astade\\Model\\components_WGNBOFKH\\component_KSEQOEET\\config_DCMYDIYK\" TARGET=Astade all",wxEXEC_ASYNC,theMakeProcess);
theMakeInputStream = theMakeProcess->GetInputStream();
theMakeErrorStream = theMakeProcess->GetErrorStream();
