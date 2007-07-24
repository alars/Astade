wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName featureEditor(theConfig->Read("Tools/FeatureEdit"));

wxTreeItemId aID = myTree->GetSelection();

wxString callName = featureEditor.GetFullPath()+" \""+myTree->GetItem(aID)->GetFileName().GetFullPath()+"\"";

//** this is for keyboard short cut
wxString ext = myTree->GetItem(aID)->GetFileName().GetExt();
wxString fullName = myTree->GetItem(aID)->GetFileName().GetFullName();
wxString fullPath = myTree->GetItem(aID)->GetFileName().GetFullPath();

if( ext == "ini")
//**
{
	wxFileConfig theConfig(wxEmptyString,wxEmptyString,fullPath);
	wxString name;
	theConfig.Read("Astade/Name", &name);
        if(name != "auto" && name != "manual" && name != "usecaseDiagrams" && name != "relations" && name != "inrelation" && name != "classes" && name != "operations" && name != "parameters" && name != "attributes")
	{ 
	//wxMessageBox(myTree->GetItem(aID)->GetFileName().GetFullName());
	//wxMessageBox(name);
	wxExecute(callName, wxEXEC_ASYNC, new AstadeChildProcess(this));
	}
}
