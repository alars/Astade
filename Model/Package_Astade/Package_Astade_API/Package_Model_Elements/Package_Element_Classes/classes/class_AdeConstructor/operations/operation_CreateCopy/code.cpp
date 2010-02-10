wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Write("Astade/Description", copyConfig.Read("Astade/Description"));
theConfig.Write("Astade/Initializer", copyConfig.Read("Astade/Initializer"));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

if (HasParameters())  //checking subdirectory from copy source.
{
	wxFileName parametersFileName = AdeParameters::CreateNewElement(aFileName.GetFullPath()); //in the copyed operation directory.

	if (theRevisionControl->IsAddSupported())
		theRevisionControl->Add(parametersFileName);

	wxFileName sourceParameter = myFileName;  //copy source path
	sourceParameter.AppendDir("parameters"); //append "parameters" directory to the path.

	wxDir dir(sourceParameter.GetPath());
    if (dir.IsOpened())
    {
		wxString filename;
	    bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_FILES); //First contents in the directory "parameter".
	    while (cont)
	    {
	        if (filename != "ModelNode.ini")
	        {
		        parametersFileName.SetFullName(filename);
		        sourceParameter.SetFullName(filename);
		        wxCopyFile(sourceParameter.GetFullPath(),parametersFileName.GetFullPath());

				AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
				if (theRevisionControl->IsAddSupported())
					theRevisionControl->Add(parametersFileName);
		    }
		    cont = dir.GetNext(&filename);
	    }
	}
}

wxFileName codeSource = myFileName;
wxFileName codeDest = aFileName;

codeSource.SetFullName("code.cpp");
codeDest.SetFullName("code.cpp");

wxCopyFile(codeSource.GetFullPath(),codeDest.GetFullPath());

if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(codeDest);

return aFileName;
