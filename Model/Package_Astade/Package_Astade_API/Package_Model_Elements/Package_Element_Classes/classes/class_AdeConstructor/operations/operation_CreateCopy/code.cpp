wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());

theConfig.Write(wxS("Astade/Type"), copyConfig.Read(wxS("Astade/Type")));
theConfig.Write(wxS("Astade/Description"), copyConfig.Read(wxS("Astade/Description")));
theConfig.Write(wxS("Astade/Initializer"), copyConfig.Read(wxS("Astade/Initializer")));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

if (HasParameters())  //checking subdirectory from copy source.
{
	wxFileName parametersFileName = AdeParameters::CreateNewElement(aFileName.GetFullPath()); //in the copyed operation directory.

	if (theRevisionControl->IsAddSupported())
		theRevisionControl->Add(parametersFileName);

	wxFileName sourceParameter = myFileName;  //copy source path
	sourceParameter.AppendDir(wxS("parameters")); //append "parameters" directory to the path.

	wxDir dir(sourceParameter.GetPath());
    if (dir.IsOpened())
    {
		wxString filename;
	    bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES); //First contents in the directory "parameter".
	    while (cont)
	    {
	        if (filename != wxS("ModelNode.ini"))
	        {
		        parametersFileName.SetFullName(filename);
		        sourceParameter.SetFullName(filename);
		        wxCopyFile(sourceParameter.GetFullPath(), parametersFileName.GetFullPath());

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

codeSource.SetFullName(wxS("code.cpp"));
codeDest.SetFullName(wxS("code.cpp"));

wxCopyFile(codeSource.GetFullPath(),codeDest.GetFullPath());

if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(codeDest);

return aFileName;
